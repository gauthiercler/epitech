/*
** NetworkManager.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Network/NetworkManager/NetworkManager.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:45:06 2017 Gauthier Cler
** Last update Sun Oct 08 22:50:39 2017 Antoine FORET
*/

#include <iostream>
#include "NetworkManager.hpp"

Spider::Network::NetworkManager::NetworkManager() {
  _server.setConnectionCallback([&](::Network::Client::clientInstance &&client) {
    this->handleNewClient(std::move(client));
  });
}

Spider::Network::NetworkManager::~NetworkManager() = default;

Spider::Network::NetworkManager &Spider::Network::NetworkManager::operator=(const Spider::Network::NetworkManager &networkManager) {
  if (this != &networkManager)
    this->_clients = networkManager._clients;
  return *this;
}

void Spider::Network::NetworkManager::handleNewClient(::Network::Client::clientInstance &&client) {
  client->startTLS();
  _clients.emplace_back(std::make_shared<::Spider::Network::Client>(client));
  // No need to use shared_from_this as the only way for this manager to go away is to exit the program
  client->setDisconnectCallback([&](const int){ handleDisconnect(_clients.back()); });
  _clients.back()->setDataCallback([&](std::string &&data) {
    try {
      _dataCallback(std::move(data), _clients.back());
    } catch (const std::bad_function_call &e) {
      std::cerr << "[NETWORK][MANAGER][ERROR] No callback set for data." << std::endl;
    }
  });
  _clients.back()->defineCallbacks();
}

void Spider::Network::NetworkManager::setDataCallback(dataCallback callback) {
  this->_dataCallback = std::move(callback);
}

void Spider::Network::NetworkManager::start(unsigned short port) {
  _server.start(port);
}

void Spider::Network::NetworkManager::handleDisconnect(const Spider::Network::Client::instance &client) {
  if (std::find(_clients.begin(), _clients.end(), client) == _clients.end())
    std::cerr << "[WARNING][NETWORK][MANAGER] Unable to find disconnected client." << std::endl;
  _clients.erase(std::find(_clients.begin(), _clients.end(), client));
  std::clog << "[INFO][NETWORK][MANAGER] " << _clients.size() << " clients remain online." << std::endl;
}

bool Spider::Network::NetworkManager::send(const std::string &mac, const std::string &data) const {
  auto client = std::find_if(_clients.begin(), _clients.end(), [&](const Spider::Network::Client::instance &clientInstance) {
    return clientInstance->getMac() == mac;
  });

  if (client != _clients.end()) {
    std::cout << "Will send" << std::endl;
    client->get()->send(data);
    return true;
  }
  else
    return false;
}

