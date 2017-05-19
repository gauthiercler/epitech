/*
** D_FLIP_FLOP.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/D_FLIP_FLOP.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Feb 25 14:43:52 2017 Anas Buyumad
** Last update Sat Feb 25 14:43:52 2017 Anas Buyumad
*/

#include "D_FLIP_FLOP.hpp"

D_FLIP_FLOP::D_FLIP_FLOP(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::CHIPSET);
  this->setNbPins(6);

  this->ClockSave = nts::Tristate::UNDEFINED;

  this->_pins.push_back(new Pin(Pin::OUTPUT, this, 1, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, this, 2, true));

  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 3, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 4, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 5, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 6, true));

  for (std::vector<Pin *>::iterator it = this->_pins.begin() ; it != this->_pins.end() ; ++it) {
    (*it)->setLinkState(false);
  }
}

D_FLIP_FLOP::~D_FLIP_FLOP() {

}

nts::Tristate	D_FLIP_FLOP::Compute(size_t pin_num_this) {
  nts::AComponent::CheckPinInRange(this->getNbPins(), pin_num_this);

  nts::Tristate NewClock = this->getPinAt(3)->Compute();
  nts::Tristate Clock = nts::Tristate::UNDEFINED;
  if (NewClock == nts::Tristate::UNDEFINED|| this->ClockSave == nts::Tristate::UNDEFINED) {
    Clock = nts::Tristate::UNDEFINED;
  }
  else if (NewClock == nts::Tristate::TRUE && this->ClockSave == nts::Tristate::FALSE) {
    Clock = nts::Tristate::TRUE;
  }
  else if (NewClock == nts::Tristate::FALSE && this->ClockSave == nts::Tristate::TRUE) {
    Clock = nts::Tristate::FALSE;
  }
  ClockSave = NewClock;
  nts::Tristate Reset = this->getPinAt(4)->Compute();
  nts::Tristate Data = this->getPinAt(5)->Compute();
  nts::Tristate Set = this->getPinAt(6)->Compute();

  if (Set || Reset) {
    if (pin_num_this == 1) {
      if (Set) {return nts::Tristate::TRUE;}
      else {return nts::Tristate::FALSE;}
    }
    else if (pin_num_this == 2) {
      if (Reset) {return nts::Tristate::TRUE;}
      else {return nts::Tristate::FALSE;}
    }
  }
  else if (Clock == nts::Tristate::TRUE) {
    if (pin_num_this == 1) {
      if (Data) {return nts::Tristate::TRUE;}
      else {return nts::Tristate::FALSE;}
    }
    else if (pin_num_this == 2) {
      if (Data) {return nts::Tristate::FALSE;}
      else {return nts::Tristate::TRUE;}
    }
  }
  else if (Clock == nts::Tristate::UNDEFINED) {return nts::Tristate::UNDEFINED;}
  else if (Clock == nts::Tristate::FALSE) {return this->getPinAt(pin_num_this)->getValue();}
  return nts::Tristate::UNDEFINED;
}