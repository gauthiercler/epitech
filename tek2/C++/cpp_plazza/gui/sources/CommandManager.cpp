/*
** CommandManager.cpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/sources/CommandManager.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Apr 14 09:53:55 2017 Vincent DUSAUTOIR
** Last update Fri Apr 14 09:53:55 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include "Utils.hpp"
#include "CommandManager.hpp"

plazza::CommandManager::CommandManager() {
  this->_regex = std::regex("^(?:.*[ \\t]+)(?:EMAIL_ADDRESS|PHONE_NUMBER|IP_ADDRESS)$");
}

plazza::CommandManager::~CommandManager() {

}

const plazza::Command &plazza::CommandManager::getCommand() const {
  return this->_command;
}

void plazza::CommandManager::parseCommand(const std::string &command) {
  std::vector<std::string>	fullCmd;
  std::string			epur;

  this->_command.reset();
  epur = Utils::epur(command);
  if (std::regex_match(epur, this->_regex)) {
    fullCmd = Utils::explode(epur, ' ');
    auto type = std::prev(fullCmd.end());
    this->_command.setType(*type);
    fullCmd.erase(type);
    this->_command.setArgs(fullCmd);
  }
}
