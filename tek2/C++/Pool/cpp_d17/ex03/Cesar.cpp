/*
** Cesar.cpp for cpp_d17 in /home/gogo/rendu/tek2/cpp_d17/ex02/Cesar.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 20 11:17:31 2017 Gauthier CLER
** Last update Fri Jan 20 11:17:31 2017 Gauthier CLER
*/

#include <iostream>
#include "Cesar.h"

Cesar::Cesar() : _shiftValue(3){

}

Cesar::~Cesar() {

}

void Cesar::encryptChar(char plainchar) {
  if ((plainchar >= 'a' && plainchar <= 'z') || (plainchar >= 'A' && plainchar <= 'Z'))
  {
    for (int it = 0; it < this->getShiftValue(); it += 1)
    {
      if (plainchar == 'z')
	plainchar = 'a';
      else if (plainchar == 'Z')
	plainchar = 'A';
      else
	plainchar += 1;
    }
  }
  std::cout << plainchar;
  this->setShiftValue(this->getShiftValue() + 1);
}

void Cesar::decryptChar(char cipherchar) {
  if ((cipherchar >= 'a' && cipherchar <= 'z') || (cipherchar >= 'A' && cipherchar <= 'Z'))
  {
    for (int it = 0; it < this->getShiftValue(); it++)
    {
      if (cipherchar == 'a')
	cipherchar = 'z';
      else if (cipherchar == 'A')
	cipherchar = 'Z';
      else
	cipherchar -= 1;
    }
  }
  std::cout << cipherchar;
  this->setShiftValue(this->getShiftValue() + 1);
}

void Cesar::reset() {
  this->setShiftValue(3);
}

void Cesar::setShiftValue(int value) {
  this->_shiftValue = value;
}

int Cesar::getShiftValue() const{
  return this->_shiftValue;
}
