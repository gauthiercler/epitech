/*
** CommandManager.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/CommandManager/CommandManager.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:44:01 2017 Gauthier Cler
** Last update Sun Oct 08 19:44:01 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_COMMANDMANAGER_HPP
#define CPP_SPIDER_COMMANDMANAGER_HPP

#include <unordered_map>
#include "Spider/Commands/ICommand.hpp"
#include "parser/Parser.hpp"

namespace Spider
{
  class CommandManager
  {
  private:
    std::unordered_map<int, std::shared_ptr<Spider::Commands::ICommand>>	_commands;

  public:
    CommandManager();
    CommandManager(const CommandManager &commandManager) = default;
    virtual ~CommandManager() = default;

    std::shared_ptr<Spider::Commands::ICommand>		get(Spider::EnumParser value);

    std::shared_ptr<Spider::Commands::ICommand>		operator[](Spider::EnumParser value);


    CommandManager		&operator=(const CommandManager &commandManager) = default;
  };
}

#endif //CPP_SPIDER_COMMANDMANAGER_HPP
