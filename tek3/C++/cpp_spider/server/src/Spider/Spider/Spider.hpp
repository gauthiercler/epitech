/*
** Spider.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Spider/Spider.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:45:26 2017 Gauthier Cler
** Last update Sun Oct 08 19:45:26 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_SPIDER_HPP
#define CPP_SPIDER_SPIDER_HPP

#include <Spider/CommandManager/CommandManager.hpp>
#include "parser/Parser.hpp"
#include "Spider/Network/NetworkManager/NetworkManager.hpp"

namespace Spider
{
  class Spider
  {
  private:
    ::Spider::Parser			_parser;
    ::DB::Manager			_dbManager;
    ::Spider::Network::NetworkManager	_networkManager;
    ::Spider::CommandManager		_commandManager;

  public:
    Spider();
    Spider(const Spider &spider) = default;
    virtual ~Spider() = default;

    void				run();
    // TODO Set disconnection callback to clean clients

    Spider				&operator=(const Spider &spider) = default;

  private:
    void				handleData(std::string &&data, ::Spider::Network::Client::instance client);

  };
}


#endif //CPP_SPIDER_SPIDER_HPP
