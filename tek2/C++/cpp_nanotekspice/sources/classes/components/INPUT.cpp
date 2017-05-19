/*
** INPUT.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/INPUT.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Feb 06 22:21:29 2017 Anas Buyumad
** Last update Mon Feb 06 22:21:29 2017 Anas Buyumad
*/

#include <iostream>
#include "INPUT.hpp"

INPUT::INPUT(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::INPUT);
  this->setNbPins(1);
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 1));
}

INPUT::~INPUT() {

}