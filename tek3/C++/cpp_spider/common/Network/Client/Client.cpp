#include <iostream>
#include <boost/bind.hpp>
#include "Network/Error.h"
#include "Network/Client/Client.hpp"

Network::Client::Client(boost::asio::ssl::context &context, boost::asio::io_service &ioService) :
  _socket(ioService, context),
  _readWrapper(ioService),
  _writeWrapper(ioService) {
}

Network::Client::~Client() {
  _socket.lowest_layer().close();
}

/*
 * Configuration
 */

void Network::Client::setReceiveCallback(readCallback callback) {
  _readCallback = std::move(callback);
}

void Network::Client::setSendCallback(Network::Client::writeCallback callback) {
  _writeCallback = std::move(callback);
}

void Network::Client::setDisconnectCallback(Network::Client::disconnectCallback callback) {
  _disconnectCallback = std::move(callback);
}

/*
 * Data reception
 */
void Network::Client::listen() {
  _socket.get_io_service().post(_readWrapper.wrap(boost::bind(&Network::Client::listenData, shared_from_this())));
}

void Network::Client::listenData() {
  _socket.async_read_some(boost::asio::buffer(_buffer), boost::bind(&Network::Client::handleData, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Network::Client::handleData(const boost::system::error_code &ec, std::size_t size) {
  if (ec.value() != 0) {
    std::cerr << "[ERROR][NETWORK][CLIENT] Unable to receive information (" << ec.message() << "). Stop listening." << std::endl;
    try {
      _disconnectCallback(ec.value());
    } catch (const std::bad_function_call &e) {
      std::clog << "[WARNING][NETWORK][CLIENT] No callback set for disconnection." << std::endl;
    }
    return ;
  }
  try {
    _readCallback(std::move(std::string(_buffer.c_array(), size)));
  } catch (const std::bad_function_call &e) {
    std::clog << "[WARNING][NETWORK][CLIENT] No callback set for new data." << std::endl;
  }
  this->listen();
}

/*
 * Send Data
 */

void Network::Client::send(const std::string &data) {
  _sendList.emplace(data);
  if (_sendList.size() == 1)
    _socket.get_io_service().post(_writeWrapper.wrap(boost::bind(&Network::Client::sendData, shared_from_this())));
}

void Network::Client::sendData() {
  if (!_sendList.empty())
    _socket.async_write_some(boost::asio::buffer(_sendList.front(), _sendList.front().length()), boost::bind(&Network::Client::sendDone, shared_from_this(), boost::asio::placeholders::error)); // TODO Manage if not all data is sent
}

void Network::Client::sendDone(const boost::system::error_code &ec) {
  if (ec.value() != 0)
  {
    std::cerr << "[ERROR][NETWORK][CLIENT] Unable to send data (" << ec.message() << ")." << std::endl;
    try {
      _disconnectCallback(ec.value());
    } catch (const std::bad_function_call &e) {
      std::clog << "[WARNING][NETWORK][CLIENT] No callback set for disconnection." << std::endl;
    }
    return ;
  }
  _sendList.pop();
  try {
    _writeCallback(true);
  } catch (const std::bad_function_call &e) {
    std::clog << "[WARNING][NETWORK][CLIENT] No callback set for data send." << std::endl;
  }
  this->sendData();
}

Network::Client::clientInstance Network::Client::connect(const std::string &host, unsigned short port, bool throwError) {
  static boost::asio::io_service	ioService;
  static boost::asio::ssl::context	ctx(ioService, boost::asio::ssl::context::tlsv12);
  boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::address::from_string(host), port);
  Network::Client::clientInstance 	client;

  try {
    ctx.set_verify_mode(boost::asio::ssl::context::verify_peer);
    ctx.load_verify_file("server.crt");
    client = std::make_shared<Network::Client>(ctx, ioService);
    client->socket().connect(endpoint);
    client->_socket.handshake(boost::asio::ssl::stream_base::client);
  } catch (const boost::system::system_error &e) {
    std::cerr << "[ERROR][NETWORK] unable to connect to " << host << ":" << port << " (" << e.what() << ")." << std::endl;
    if (throwError)
      throw Network::NetworkError("Unable to connect to " + host + ":" + std::to_string(port));
  }
  return client;
}

void Network::Client::waitForData() {
  _socket.get_io_service().run();
}

void Network::Client::syncSend(const std::string &data) {
  std::string buff(data);
  size_t toSend = data.size();
  size_t sent;

  while (toSend != 0)
  {
    try {
      sent = _socket.write_some(boost::asio::buffer(buff));
    } catch (const boost::system::system_error &e) {
      std::cerr << "[ERROR][NETWORK] unable to send data to " << _socket.lowest_layer().remote_endpoint().address() << ":" << _socket.lowest_layer().remote_endpoint().port() << std::endl;
	throw Network::NetworkError("Unable to connect to " + _socket.lowest_layer().remote_endpoint().address().to_string() + ":" + std::to_string(_socket.lowest_layer().remote_endpoint().port()));
    }
    toSend -= sent;
    buff = buff.substr(sent, toSend);
  }
}

void Network::Client::disconnect() {
  _socket.lowest_layer().close();
  try {
    _disconnectCallback(1);
  } catch (const std::bad_function_call &e) {
    std::clog << "[WARNING][NETWORK][CLIENT] No callback set for disconnection." << std::endl;
  }
}

Network::Client::ssl_socket::lowest_layer_type &Network::Client::socket() {
  return _socket.lowest_layer();
}

void Network::Client::startTLS() {
  _socket.async_handshake(boost::asio::ssl::stream_base::server, boost::bind(&Network::Client::handleHandshake, shared_from_this(), boost::asio::placeholders::error));
}

void Network::Client::handleHandshake(const boost::system::error_code &ec) {
  if (!ec)
    listen();
  else
  {
    std::cout << "[WARNING][NETWORK] Client failed TLS Connection. Closing connection." << std::endl;
    disconnect();
  }
}
