/*
** C4071.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4071.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:42:17 2017 Anas Buyumad
** Last update Fri Jan 27 20:42:17 2017 Anas Buyumad
*/

#include <sources/classes/components/gates/OR.hpp>
#include <iostream>
#include "C4071.hpp"

C4071::C4071(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::CHIPSET);
  this->setNbPins(14);

  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 1, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 2, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 3, true));

  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 4, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 5, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 6, true));

  this->_pins.push_back(new Pin(Pin::IGNORED, NULL, 7, true));

  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 8, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 9, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 10, true));

  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 11, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 12, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 13, true));

  this->_pins.push_back(new Pin(Pin::IGNORED, NULL, 14, true));

  nts::IComponent	*FirstOR = new OR();
  this->SetLink(1, *FirstOR, 1);
  this->SetLink(2, *FirstOR, 2);
  this->SetLink(3, *FirstOR, 3);
  this->_innerCircuit.push_back(FirstOR);

  nts::IComponent	*SecondOR = new OR();
  this->SetLink(4, *SecondOR, 3);
  this->SetLink(5, *SecondOR, 2);
  this->SetLink(6, *SecondOR, 1);
  this->_innerCircuit.push_back(SecondOR);

  nts::IComponent	*ThirdOR = new OR();
  this->SetLink(8, *ThirdOR, 1);
  this->SetLink(9, *ThirdOR, 2);
  this->SetLink(10, *ThirdOR, 3);
  this->_innerCircuit.push_back(ThirdOR);

  nts::IComponent	*FourthOR = new OR();
  this->SetLink(11, *FourthOR, 3);
  this->SetLink(12, *FourthOR, 2);
  this->SetLink(13, *FourthOR, 1);
  this->_innerCircuit.push_back(FourthOR);

  for (std::vector<Pin *>::iterator it = this->_pins.begin() ; it != this->_pins.end() ; ++it) {
    (*it)->setLinkState(false);
  }
}

C4071::~C4071() {
}