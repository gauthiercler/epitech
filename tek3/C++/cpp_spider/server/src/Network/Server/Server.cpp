/*
** Server.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Network/Server/Server.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:43:02 2017 Gauthier Cler
** Last update Sun Oct 08 19:43:02 2017 Gauthier Cler
*/

#include <iostream>
#include <boost/bind.hpp>
#include "Server.hpp"

Network::Server::Server() :
  _started(false),
  _acceptor(_ioService),
  _client(nullptr),
  _context(_ioService, boost::asio::ssl::context::tlsv12)
{
  defineContext();
  createClient();
  //_socket = std::move(ssl_socket(_ioService, _context));
}

Network::Server::~Server() {
  _acceptor.close();
}

void Network::Server::setConnectionCallback(Network::Server::connectionCallback callback) {
  this->_connectionCallback = std::move(callback);
}

void Network::Server::start(const unsigned short port) {
  if (!this->_started)
  {
    this->listen(port);
    this->accept();
    this->_ioService.run();
  }
}

void Network::Server::listen(const unsigned short port) {
  boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);

  try
  {
    this->_acceptor.open(endpoint.protocol());
    this->_acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    this->_acceptor.bind(endpoint);
    this->_acceptor.listen();
    std::clog << "[INFO][NETWORK] Start listening on " << endpoint.address() << ":" << endpoint.port() << "." << std::endl;
  } catch (const boost::system::system_error &e) {
    std::cerr << "[ERROR][NETWORK] Unable to listen on port " << port << " (" << e.what() << ")." << std::endl;
  }
}

void Network::Server::accept() {
  // No need to do a shared_from_this as if instance goes away ec in handleConnection will be non zero (error caused by acceptor closed) and so will not use any element from this
  _acceptor.async_accept(_client->socket(), boost::bind(&Network::Server::handleConnection, this, boost::asio::placeholders::error));
}

void Network::Server::handleConnection(const boost::system::error_code &ec) {
  if (ec.value() == 0) {
    try {
      std::cout << "[INFO][NETWORK] New connection." << std::endl;
      _connectionCallback(std::move(_client));
      createClient();
    } catch (const std::bad_function_call &e) {
      std::clog << "[WARNING][NETWORK] No callback set for new client." << std::endl;
    }
    this->accept();
  }
  else
    std::cerr << "[ERROR][NETWORK] Unable to accept client. Stop listening." << std::endl;
}

void Network::Server::createClient() {
  _client = std::make_shared<Network::Client>(_context, _ioService);
}

std::string Network::Server::getPassword() {
  std::string password;

  std::cout << "Enter key password: ";
  std::getline(std::cin, password);
  return std::move(password);
}

void Network::Server::defineContext() {
  _context.set_options(
    boost::asio::ssl::context::default_workarounds
    | boost::asio::ssl::context::no_sslv2
    | boost::asio::ssl::context::single_dh_use);
  try {
    _context.set_password_callback(boost::bind(&Network::Server::getPassword, this));
    _context.use_certificate_chain_file("certs/server.crt");
    _context.use_private_key_file("certs/server.key", boost::asio::ssl::context::pem);
    _context.use_tmp_dh_file("certs/dhparam.pem");
  } catch (const boost::system::system_error &e) {
    std::cerr << "[ERROR][NETWORK] Unable to define TLS context (" << e.what() << ")." << std::endl;
  }
}
