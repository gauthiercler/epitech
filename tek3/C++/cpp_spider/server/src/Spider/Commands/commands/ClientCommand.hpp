/*
** ClientCommand.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Commands/commands/ClientCommand.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:44:14 2017 Gauthier Cler
** Last update Sun Oct 08 19:44:14 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_CLIENTCOMMAND_HPP
#define CPP_SPIDER_CLIENTCOMMAND_HPP

#include "Spider/Commands/ICommand.hpp"

namespace Spider
{
  namespace Commands
  {
    class ClientCommand : public ICommand
    {
    private:

    public:
      ClientCommand() = default;
      ClientCommand(const ClientCommand &) = default;
      virtual ~ClientCommand() = default;

      virtual bool		run(const std::string &data, Spider::Network::Client::instance client, DB::Manager &manager);

      ClientCommand		&operator=(const ClientCommand &) = default;
    };
  }
}


#endif //CPP_SPIDER_CLIENTCOMMAND_HPP
