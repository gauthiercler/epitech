/*
** XorCypher.cpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/sources/XorCypher.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Apr 25 13:31:58 2017 Vincent DUSAUTOIR
** Last update Tue Apr 25 13:31:58 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include "XorCypher.hpp"

plazza::XorCypher::XorCypher() {

}

plazza::XorCypher::~XorCypher() {

}

void plazza::XorCypher::encrypt(std::string &buffer) {
  std::string encrypt;
  size_t idx = 0;

  if (this->getKey().size() > 0)
  {
    for (auto c : buffer) {
      encrypt += c ^ this->getKey()[idx % this->getKey().size()];
      idx++;
    }
    buffer = encrypt;
  }
}

void plazza::XorCypher::decrypt(std::string &buffer) {
  this->encrypt(buffer);
}

const std::string &plazza::XorCypher::getKey() const {
  return this->_key;
}

void plazza::XorCypher::setKey(const std::string &key) {
  this->_key = key;
}
