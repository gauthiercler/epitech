/*
** NOT.cpp for cpp_nanotekspice in /home/gogo/rendu/tek2/cpp_nanotekspice/sources/classes/components/gates/NOT.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Feb 17 16:40:25 2017 Gauthier Cler
** Last update Fri Feb 17 16:40:25 2017 Gauthier Cler
*/

#include "NOT.hpp"

NOT::NOT(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::CHIPSET);
  this->setNbPins(2);
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 1));
  this->_pins.push_back(new Pin(Pin::OUTPUT, this, 2));
}

NOT::~NOT() {

}

nts::Tristate NOT::Compute(size_t pin_num_this) {
  nts::AComponent::CheckPinInRange(this->getNbPins(), pin_num_this);
  if (pin_num_this == 2) {
    if (this->getPinAt(2)->isLocked()) {
      nts::Tristate Input = this->getPinAt(1)->Compute();
      if (Input == nts::Tristate::UNDEFINED)
	return nts::Tristate::UNDEFINED;
      return (Input == nts::Tristate::TRUE) ? nts::Tristate::FALSE : nts::Tristate::TRUE;
    }
  }
  return this->getPinAt(pin_num_this)->Compute();
}
