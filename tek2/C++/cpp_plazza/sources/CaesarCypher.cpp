/*
** CaesarCypher.cpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/sources/CaesarCypher.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Apr 25 16:29:38 2017 Vincent DUSAUTOIR
** Last update Tue Apr 25 16:29:38 2017 Vincent DUSAUTOIR
*/

#include "CaesarCypher.hpp"

plazza::CaesarCypher::CaesarCypher() : _moved(0) {

}

plazza::CaesarCypher::~CaesarCypher() {

}

void plazza::CaesarCypher::encrypt(std::string &buffer) {
  std::string encrypt;

  for (auto &c : buffer) {
    encrypt += c - this->getMoved();
  }
  buffer = encrypt;
}

void plazza::CaesarCypher::decrypt(std::string &buffer) {
  std::string decrypt;

  for (auto &c : buffer) {
    decrypt += c + this->getMoved();
  }
  buffer = decrypt;
}

size_t plazza::CaesarCypher::getMoved() const {
  return this->_moved;
}

void plazza::CaesarCypher::setMoved(const size_t moved) {
  this->_moved = moved;
}
