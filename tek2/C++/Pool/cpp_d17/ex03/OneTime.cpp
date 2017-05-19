/*
** OneTime.cpp for cpp_d17 in /home/gogo/rendu/tek2/cpp_d17/ex02/OneTime.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 20 11:17:42 2017 Gauthier CLER
** Last update Fri Jan 20 11:17:42 2017 Gauthier CLER
*/

#include <iostream>
#include "OneTime.h"

OneTime::OneTime(const std::string &key) : _key(key), _shiftValue(0){
  char	current = 'a';
  for (int i = 0; i <= 26; i++)
  {
    this->_array[current] = i;
    this->_array[current - 32] = i;
    current += 1;
  }
}

OneTime::~OneTime() {

}

void OneTime::encryptChar(char plainchar) {

  while (this->getShiftValue() >= (int)this->_key.length())
    this->setShiftValue(this->getShiftValue() - (int)this->_key.length());
  char		keyChar = this->_key.c_str()[this->getShiftValue()];

  if ((plainchar >= 'a' && plainchar <= 'z') || (plainchar >= 'A' && plainchar <= 'Z')) {
    for (int it = 0; it < this->_array[keyChar]; it += 1)
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

void OneTime::decryptChar(char cypherchar) {

  while (this->getShiftValue() >= (int)this->_key.length())
    this->setShiftValue(this->getShiftValue() - (int)this->_key.length());
  char		keyChar = this->_key.c_str()[this->getShiftValue()];

  if ((cypherchar >= 'a' && cypherchar <= 'z') || (cypherchar >= 'A' && cypherchar <= 'Z')) {
    for (int it = 0; it < this->_array[keyChar]; it += 1)
    {
      if (cypherchar == 'a')
	cypherchar = 'z';
      else if (cypherchar == 'A')
	cypherchar = 'Z';
      else
	cypherchar -= 1;
    }
  }
  std::cout << cypherchar;
  this->setShiftValue(this->getShiftValue() + 1);
}

void OneTime::reset() {
  this->setShiftValue(0);
}

void OneTime::setShiftValue(int value) {
  this->_shiftValue = value;
}

int OneTime::getShiftValue() const {
  return this->_shiftValue;
}
