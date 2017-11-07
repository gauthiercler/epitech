/*
** ICommand.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Commands/ICommand.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:44:59 2017 Gauthier Cler
** Last update Sun Oct 08 19:44:59 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_ICOMMAND_HPP
#define CPP_SPIDER_ICOMMAND_HPP

#include <string>
#include "database/Manager.hpp"
#include "Spider/Network/Client/Client.hpp"

namespace Spider
{
  namespace Commands
  {
    class ICommand
    {
    public:
      virtual ~ICommand() = default;
      virtual bool	run(const std::string &data, Spider::Network::Client::instance client, DB::Manager &manager) = 0;
    };
  }
}



#endif //CPP_SPIDER_ICOMMAND_HPP
