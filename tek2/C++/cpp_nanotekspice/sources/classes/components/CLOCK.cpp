/*
** CLOCK.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/CLOCK.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Feb 09 22:19:19 2017 Anas Buyumad
** Last update Thu Feb 09 22:19:19 2017 Anas Buyumad
*/

#include <iostream>
#include "CLOCK.hpp"

CLOCK::CLOCK(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::CLOCK);
  this->setNbPins(1);
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 1));
}

CLOCK::~CLOCK() {

}

void CLOCK::InvertClock() {
  nts::Tristate CurrentState = this->getPinAt(1)->getValue();
  this->Save = CurrentState;
  if (CurrentState == nts::Tristate::TRUE || CurrentState == nts::Tristate::FALSE) {
    (CurrentState == nts::Tristate::TRUE) ? (this->getPinAt(1)->setValue(nts::Tristate::FALSE)) : this->getPinAt(1)->setValue(nts::Tristate::TRUE);
  }
}

nts::Tristate CLOCK::getSave(void) {
  return this->Save;
}
