/*
** pingCommand.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Commands/commands/pingCommand.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:44:53 2017 Gauthier Cler
** Last update Sun Oct 08 19:44:53 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_PINGCOMMAND_HPP
#define CPP_SPIDER_PINGCOMMAND_HPP

#include "Spider/Commands/ICommand.hpp"

namespace Spider
{
  namespace Commands
  {
    class pingCommand : public Spider::Commands::ICommand
    {
    private:

    public:
      pingCommand() = default;
      pingCommand(const pingCommand &) = default;
      virtual ~pingCommand() = default;

      virtual bool		run(const std::string &data, Spider::Network::Client::instance client, DB::Manager &manager);

      pingCommand		&operator=(const pingCommand &) = default;
    };
  }
}


#endif //CPP_SPIDER_PINGCOMMAND_HPP
