/*
** TRUE.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/TRUE.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Feb 05 20:08:43 2017 Anas Buyumad
** Last update Sun Feb 05 20:08:44 2017 Anas Buyumad
*/

#include <iostream>
#include "True.hpp"

True::True(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::CHIPSET);
  this->setNbPins(1);
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 1));

  this->getPinAt(1)->setValue(nts::Tristate::TRUE);
}

True::~True() {

}