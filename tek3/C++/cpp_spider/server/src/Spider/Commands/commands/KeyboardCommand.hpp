/*
** KeyboardCommand.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Commands/commands/KeyboardCommand.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:44:28 2017 Gauthier Cler
** Last update Sun Oct 08 19:44:28 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_KEYBOARDCOMMAND_HPP
#define CPP_SPIDER_KEYBOARDCOMMAND_HPP

#include "Spider/Commands/ICommand.hpp"

namespace Spider
{
  namespace Commands
  {
    class KeyboardCommand : public Spider::Commands::ICommand
    {
    private:

    public:
      KeyboardCommand() = default;
      KeyboardCommand(const KeyboardCommand &) = default;
      virtual ~KeyboardCommand() = default;

      virtual bool		run(const std::string &data, Spider::Network::Client::instance client, DB::Manager &manager);

      KeyboardCommand		&operator=(const KeyboardCommand &) = default;
    };
  }
}


#endif //CPP_SPIDER_KEYBOARDCOMMAND_HPP
