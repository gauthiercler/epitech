#include <iostream>
#include <utility>
#include "Client.hpp"

Spider::Network::Client::Client(::Network::Client::clientInstance client) :
  _client(std::move(client)),
  _buff()
{}


void Spider::Network::Client::handleData(std::string &&data) {
  _buff += data;
  long size = getJsonSize();
  if (size >= 0) {
    try {
      std::string json(_buff, 0, size);
      _buff = _buff.substr(size, _buff.size() - size);
      _dataCallback(std::move(json));
      handleData("");
    } catch (std::bad_function_call &e) {
      std::cerr << "[SPIDER][NETWORK][CLIENT] No callback set for data." << std::endl;
    }
  }
}

void Spider::Network::Client::send(const std::string &data) {
  _client->send(data);
}

Spider::Network::Client::instance Spider::Network::Client::connect(const std::string &host, unsigned short port, bool throwError) {
  ::Network::Client::clientInstance clientInstance = ::Network::Client::connect(host, port, throwError);

  clientInstance->listen();
  return std::make_shared<Spider::Network::Client>(Spider::Network::Client(clientInstance));
}

void Spider::Network::Client::listen() {
  defineCallbacks();
  _client->waitForData();
}

void Spider::Network::Client::setDataCallback(Spider::Network::Client::dataCallback callback) {
  _dataCallback = std::move(callback);
}

long int Spider::Network::Client::getJsonSize() {
  size_t	size = 0;
  unsigned int	depth = 0;
  char		catchedChar = '\0';
  bool		escapped = false;

  for (auto it : _buff) {
    if (it == '{' && !escapped && catchedChar == '\0')
      depth += 1;
    else if (it == '}' && !escapped && catchedChar == '\0')
      depth -= 1;
    else if (it == catchedChar && !escapped)
      catchedChar = '\0';
    else if ((it == '\'' || it == '"') && catchedChar == '\0')
      catchedChar = it;
    escapped = (it == '\\');
    size += 1;
    if (depth == 0)
      return size;
  }
  return -1;
}

void Spider::Network::Client::setMac(const std::string &mac) {
  _mac = mac;
}

const std::string &Spider::Network::Client::getMac() const {
  return _mac;
}

void Spider::Network::Client::syncSend(const std::string &data) {
  _client->syncSend(data);
}

void Spider::Network::Client::disconnect() {
  _client->disconnect();
}

void Spider::Network::Client::setDisconnectCallback(Network::Client::disconnectCallback callback) {
  _client->setDisconnectCallback(std::move(callback));
}

void Spider::Network::Client::defineCallbacks() {
  _client->setReceiveCallback(std::bind(&Spider::Network::Client::handleData, shared_from_this(), std::placeholders::_1));
  _client->setSendCallback(std::bind(&Spider::Network::Client::handleWrite, shared_from_this(), std::placeholders::_1));
}

void Spider::Network::Client::handleWrite(bool &&) const {}
