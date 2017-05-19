/*
** Encryption.cpp for cpp_d17 in /home/gogo/rendu/tek2/cpp_d17/ex03/Encryption.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 20 14:29:42 2017 Gauthier CLER
** Last update Fri Jan 20 14:29:42 2017 Gauthier CLER
*/

#include <clocale>
#include <iostream>
#include <algorithm>
#include "Encryption.h"

Encryption::Encryption(IEncryptionMethod &method, void (IEncryptionMethod::*ptr)(char character)) {
  this->_ptr = ptr;
  this->_method = &method;
}

Encryption::~Encryption() {

}

Encryption &Encryption::operator()(char character) {
  (this->_method->*(_ptr))(character);
  return *this;
}

void Encryption::encryptString(IEncryptionMethod &encryptionMethod, std::string const &toEncrypt) {
  encryptionMethod.reset();
  std::for_each(toEncrypt.begin(), toEncrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::encryptChar));
  std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod &encryptionMethod, std::string const &toDecrypt) {
  encryptionMethod.reset();
  std::for_each(toDecrypt.begin(), toDecrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::decryptChar));
  std::cout << std::endl;
}
