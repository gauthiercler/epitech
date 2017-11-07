/*
** CommandResponseCommand.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Commands/commands/CommandResponseCommand.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:44:21 2017 Gauthier Cler
** Last update Sun Oct 08 19:44:21 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_COMMANDRESPONSE_HPP
#define CPP_SPIDER_COMMANDRESPONSE_HPP

#include "Spider/Commands/ICommand.hpp"

namespace Spider
{
  namespace Commands
  {
    class CommandResponseCommand : public Spider::Commands::ICommand
    {
    private:

    public:
      CommandResponseCommand() = default;
      CommandResponseCommand(const CommandResponseCommand &) = default;
      virtual ~CommandResponseCommand() = default;

      virtual bool		run(const std::string &data, Spider::Network::Client::instance client, DB::Manager &manager);

      CommandResponseCommand		&operator=(const CommandResponseCommand &) = default;
    };
  }
}


#endif //CPP_SPIDER_COMMANDRESPONSE_HPP
