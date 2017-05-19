/*
** FLIP_FLOP.cpp for cpp_nanotekspice in /home/gogo/rendu/tek2/cpp_nanotekspice/sources/classes/components/FLIP_FLOP.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Feb 25 19:05:00 2017 Gauthier Cler
** Last update Sat Feb 25 19:05:00 2017 Gauthier Cler
*/

#include "FLIP_FLOP.hpp"

FLIP_FLOP::FLIP_FLOP(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::CHIPSET);
  this->setNbPins(4);

  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 1, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 2, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, this, 3, false));
  this->_pins.push_back(new Pin(Pin::OUTPUT, this, 4, false));
}

FLIP_FLOP::~FLIP_FLOP() {

}

nts::Tristate FLIP_FLOP::Compute(size_t pin_num_this) {
  nts::AComponent::CheckPinInRange(this->getNbPins(), pin_num_this);
  if ((pin_num_this == 3 || pin_num_this == 4) && this->getPinAt(pin_num_this)->isLocked()) {
    nts::Tristate firstInput = this->getPinAt(1)->Compute();
    nts::Tristate secondInput = this->getPinAt(2)->Compute();
    if (firstInput == nts::Tristate::UNDEFINED ||
	secondInput == nts::Tristate::UNDEFINED)
      return nts::Tristate::UNDEFINED;
    if (firstInput == nts::Tristate::TRUE &&
	secondInput == nts::Tristate::TRUE)
      return this->getPinAt(pin_num_this)->getValue();
    if (firstInput == nts::Tristate::FALSE &&
	secondInput == nts::Tristate::FALSE)
      return nts::Tristate::UNDEFINED;
    if (pin_num_this == 3)
      return (firstInput == nts::Tristate::FALSE && secondInput == nts::Tristate::TRUE) ? nts::Tristate::TRUE : nts::Tristate::FALSE;
    else
      return (firstInput == nts::Tristate::TRUE && secondInput == nts::Tristate::FALSE) ? nts::Tristate::FALSE : nts::Tristate::TRUE;
  }
  return this->getPinAt(pin_num_this)->Compute();
}
