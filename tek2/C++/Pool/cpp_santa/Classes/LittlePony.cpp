/*
** LittlePony.cpp for cpp_santa in /home/rubysh/Work/Repositories/Epitech/SecondYear/Pool/cpp_santa/Classes/LittlePony.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jan 14 14:33:23 2017 Anas Buyumad
** Last update Sat Jan 14 14:33:23 2017 Anas Buyumad
*/

#include <iostream>
#include "LittlePony.hpp"

LittlePony::LittlePony(const std::string &name) : AToy(name) {

}

LittlePony::LittlePony(const LittlePony &pony) : AToy(pony.getName()) {

}

LittlePony::~LittlePony() {

}

bool LittlePony::isTaken() {
  if (!this->getTaken()) {
    std::cout << "yo man" << std::endl;
    this->setTaken(true);
    return true;
  }
  return false;
}

LittlePony *LittlePony::clone() const {
  return new LittlePony(*this);
}

LittlePony &LittlePony::operator=(const LittlePony &pony) {
  this->_name = pony.getName();
  this->_taken = false;
  return *this;
}

bool LittlePony::isPut() {
  if (this->getTaken()) {
    std::cout << "[" << this->getName() << "] : Take me back please..." << std::endl;
    this->setTaken(false);
    return true;
  }
  return false;
}
