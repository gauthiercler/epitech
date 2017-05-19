/*
** Teddy.cpp for cpp_santa in /home/rubysh/Work/Repositories/Epitech/SecondYear/Pool/cpp_santa/Classes/Teddy.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jan 14 15:31:57 2017 Anas Buyumad
** Last update Sat Jan 14 15:31:57 2017 Anas Buyumad
*/

#include <iostream>
#include "Teddy.hpp"

Teddy::Teddy(const std::string &name) : AToy(name) {
}

Teddy::Teddy(const Teddy &teddy) : AToy(teddy.getName()) {

}

Teddy::~Teddy() {

}

bool Teddy::isTaken() {
  if (!this->getTaken()) {
    std::cout << "gra hu" << std::endl;
    this->setTaken(true);
    return true;
  }
  return false;
}

Teddy *Teddy::clone() const {
  return new Teddy(*this);
}

Teddy &Teddy::operator=(const Teddy &teddy) {
  this->_name = teddy.getName();
  this->_taken = false;
  return *this;
}

bool Teddy::isPut() {
  if (this->getTaken()) {
    std::cout << "[" << this->getName() << "] : Take me back please..." << std::endl;
    this->setTaken(false);
    return true;
  }
  return false;
}
