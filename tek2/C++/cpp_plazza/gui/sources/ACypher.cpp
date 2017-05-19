/*
** ADecrypt.cpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/sources/ADecrypt.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Apr 25 11:27:56 2017 Vincent DUSAUTOIR
** Last update Tue Apr 25 11:27:57 2017 Vincent DUSAUTOIR
*/

#include "ACypher.hpp"

plazza::ACypher::~ACypher() {

}

plazza::ACypher &plazza::ACypher::operator<<(std::string &buffer) {
  this->encrypt(buffer);
  return *this;
}

plazza::ACypher &plazza::ACypher::operator>>(std::string &buffer) {
  this->decrypt(buffer);
  return *this;
}
