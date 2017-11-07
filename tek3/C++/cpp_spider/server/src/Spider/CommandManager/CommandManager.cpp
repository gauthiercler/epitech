/*
** CommandManager.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/CommandManager/CommandManager.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:43:57 2017 Gauthier Cler
** Last update Sun Oct 08 19:43:57 2017 Gauthier Cler
*/

#include "CommandManager.hpp"
#include "Spider/Commands/commands/pingCommand.hpp"
#include "Spider/Commands/commands/ClientCommand.hpp"
#include "Spider/Commands/commands/KeyboardCommand.hpp"
#include "Spider/Commands/commands/MouseCommand.hpp"
#include "Spider/Commands/commands/CommandResponseCommand.hpp"

Spider::CommandManager::CommandManager() {
  this->_commands[static_cast<int>(Spider::EnumParser::PING)] = std::make_shared<Spider::Commands::pingCommand>();
  this->_commands[static_cast<int>(Spider::EnumParser::CLIENT)] = std::make_shared<Spider::Commands::ClientCommand>();
  this->_commands[static_cast<int>(Spider::EnumParser::KEYBOARD)] = std::make_shared<Spider::Commands::KeyboardCommand>();
  this->_commands[static_cast<int>(Spider::EnumParser::MOUSE)] = std::make_shared<Spider::Commands::MouseCommand>();
  this->_commands[static_cast<int>(Spider::EnumParser::COMMAND_RESPONSE)] = std::make_shared<Spider::Commands::CommandResponseCommand>();
}

std::shared_ptr<Spider::Commands::ICommand> Spider::CommandManager::get(Spider::EnumParser value) {
  return _commands[static_cast<int>(value)];
}

std::shared_ptr<Spider::Commands::ICommand> Spider::CommandManager::operator[](Spider::EnumParser value) {
  return get(value);
}
