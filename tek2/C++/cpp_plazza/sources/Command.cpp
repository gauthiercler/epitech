/*
** Command.cpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/sources/Command.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Apr 14 09:49:57 2017 Vincent DUSAUTOIR
** Last update Fri Apr 14 09:49:58 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include "Command.hpp"

plazza::Command::Command() : _type(Information::UNKNOWN) {
  this->_stringCommandType.insert({"EMAIL_ADDRESS", Information::EMAIL_ADDRESS});
  this->_stringCommandType.insert({"IP_ADDRESS", Information::IP_ADDRESS});
  this->_stringCommandType.insert({"PHONE_NUMBER", Information::PHONE_NUMBER});
  this->_stringCommandType.insert({"UNKNOWN", Information::UNKNOWN});
}

plazza::Command::~Command() {

}

Information plazza::Command::getType() const {
  return this->_type;
}

const std::vector<std::string> &plazza::Command::getArgs() const {
  return this->_args;
}

void plazza::Command::setType(const Information type) {
  this->_type = type;
}

void plazza::Command::setArgs(const std::vector<std::string> &args) {
  this->_args = args;
}

void plazza::Command::reset() {
  this->setType(Information::UNKNOWN);
  this->_args.clear();
}

void plazza::Command::setType(const std::string &type) {
  auto found = this->_stringCommandType.find(type);
  if (found != this->_stringCommandType.end())
    this->setType(found->second);
  else
    this->setType(Information::UNKNOWN);
}

void plazza::Command::display() const {
  std::cout << "===COMMAND===" << std::endl;
  std::cout << "Type : ";
  for (auto &it : this->_stringCommandType) {
    if (it.second == this->_type)
      std::cout << it.first << std::endl;
  }
  std::cout << "Args : " << std::endl;
  for (auto &it : this->_args) {
    std::cout << it << std::endl;
  }
  std::cout << "=============" << std::endl;
}
