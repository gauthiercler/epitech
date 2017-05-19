/*
** False.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/False.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Feb 06 21:34:02 2017 Anas Buyumad
** Last update Mon Feb 06 21:34:06 2017 Anas Buyumad
*/

#include <iostream>
#include "False.hpp"

False::False(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::CHIPSET);
  this->setNbPins(1);
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 1));

  this->getPinAt(1)->setValue(nts::Tristate::FALSE);
}

False::~False() {

}