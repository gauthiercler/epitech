/*
** Buffer.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/server/Buffer.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Jun 26 17:35:15 2017 Vincent DUSAUTOIR
** Last update Mon Jun 26 17:35:15 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include "server/Buffer.hpp"

zappy::Buffer::Buffer() {

}

zappy::Buffer::~Buffer() {

}

void zappy::Buffer::add(const std::string &sentence) {
  this->_buffer += sentence;
}

const std::string &zappy::Buffer::getBuffer() const {
  return this->_buffer;
}

std::string zappy::Buffer::getLine() {
  std::string line;
  std::size_t pos = this->_buffer.find_first_of("\n");

  if (pos != std::string::npos)
  {
    line = this->_buffer.substr(0, pos);
    this->_buffer = this->_buffer.erase(0, pos + 1);
  }
  return line;
}

