/*
** File.cpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/sources/File.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Apr 24 20:21:47 2017 Vincent DUSAUTOIR
** Last update Mon Apr 24 20:21:47 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include "File.hpp"

plazza::File::File() : _open(false) {

}

plazza::File::File(const std::string &filename) : _open(false) {
  this->load(filename);
}

plazza::File::~File() {

}

const std::string &plazza::File::getFilename() const {
  return this->_filename;
}

void plazza::File::load(const std::string &filename) {
  std::string	line;
  std::ifstream	file;

  this->_filename = filename;
  file.open(filename);
  this->setOpen(file.is_open());
  if (this->isOpen()) {
    this->_buffer.str("");
    while (std::getline(file, line)) {
      this->_buffer << line << std::endl;
    }
  }
}

bool plazza::File::isOpen() const {
  return this->_open;
}

std::string plazza::File::getBuffer() const {
  return this->_buffer.str();
}

void plazza::File::setOpen(const bool open) {
  this->_open = open;
}
