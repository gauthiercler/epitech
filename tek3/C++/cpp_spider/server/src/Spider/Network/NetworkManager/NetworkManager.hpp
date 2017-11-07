/*
** NetworkManager.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Network/NetworkManager/NetworkManager.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:45:11 2017 Gauthier Cler
** Last update Sun Oct 08 19:45:11 2017 Gauthier Cler
*/

#ifndef SPIDER_NETWORKMANAGER_HPP
#define SPIDER_NETWORKMANAGER_HPP

#include <Network/Client/Client.hpp>
#include <Network/Server/Server.hpp>
#include "Spider/Network/Client/Client.hpp"

namespace Spider
{
  namespace Network
  {
    class NetworkManager
    {
    public:
      typedef std::function<void (std::string &&, ::Spider::Network::Client::instance client)>	dataCallback;

    private:
      ::Network::Server					_server;
      std::vector<Spider::Network::Client::instance>	_clients;
      dataCallback					_dataCallback;

    public:
      NetworkManager();
      NetworkManager(const NetworkManager &networkManager) = delete;
      ~NetworkManager();

      void					setDataCallback(dataCallback callback);

      void					start(unsigned short port = 7075);

      bool					send(const std::string &mac, const std::string &data) const;

      NetworkManager				&operator=(const NetworkManager &networkManager);

    private:
      void					handleNewClient(::Network::Client::clientInstance &&client);
      void					handleDisconnect(const Spider::Network::Client::instance &client);
    };
  }
}

#endif //SPIDER_NETWORKMANAGER_HPP
