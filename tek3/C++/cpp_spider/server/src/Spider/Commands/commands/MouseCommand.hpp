/*
** MouseCommand.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Commands/commands/MouseCommand.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:44:41 2017 Gauthier Cler
** Last update Sun Oct 08 19:44:41 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_MOUSECOMMAND_HPP
#define CPP_SPIDER_MOUSECOMMAND_HPP

#include "Spider/Commands/ICommand.hpp"

namespace Spider
{
  namespace Commands
  {
    class MouseCommand : public ICommand
    {
    private:

    public:
      MouseCommand() = default;
      MouseCommand(const MouseCommand &) = default;
      virtual ~MouseCommand() = default;

      virtual bool		run(const std::string &data, Spider::Network::Client::instance client, DB::Manager &manager);

      MouseCommand		&operator=(const MouseCommand &) = default;
    };
  }
}


#endif //CPP_SPIDER_MOUSECOMMAND_HPP
