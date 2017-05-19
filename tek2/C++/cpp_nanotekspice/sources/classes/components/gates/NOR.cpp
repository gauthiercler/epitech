/*
** NOR.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/gates/NOR.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:29:46 2017 Anas Buyumad
** Last update Fri Jan 27 20:29:46 2017 Anas Buyumad
*/

#include <iostream>
#include "NOR.hpp"

NOR::NOR(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::CHIPSET);
  this->setNbPins(3);
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 1));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 2));
  this->_pins.push_back(new Pin(Pin::OUTPUT, this, 3));
}

NOR::~NOR() {

}

nts::Tristate NOR::Compute(size_t pin_num_this) {
  nts::AComponent::CheckPinInRange(this->getNbPins(), pin_num_this);
  if (pin_num_this == 3) {
    if (this->getPinAt(3)->isLocked()) {

      nts::Tristate InputA = this->getPinAt(1)->Compute();
      nts::Tristate InputB = this->getPinAt(2)->Compute();

      if (InputA == nts::Tristate::TRUE || InputB == nts::Tristate::TRUE) {
	return nts::Tristate::FALSE;
      }
      else if (InputA == nts::Tristate::UNDEFINED || InputB == nts::Tristate::UNDEFINED) {
	return nts::Tristate::UNDEFINED;
      }
      return nts::Tristate::TRUE;
    }
  }
  return this->getPinAt(pin_num_this)->Compute();
}