/*
** OUTPUT.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/OUTPUT.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Feb 07 17:40:36 2017 Anas Buyumad
** Last update Tue Feb 07 17:40:37 2017 Anas Buyumad
*/

#include <iostream>
#include "OUTPUT.hpp"

OUTPUT::OUTPUT(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::OUTPUT);
  this->setNbPins(1);
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 1));
}

OUTPUT::~OUTPUT() {

}