/*
** C4011.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4011.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:37:58 2017 Anas Buyumad
** Last update Fri Jan 27 20:37:58 2017 Anas Buyumad
*/

#include <sources/classes/components/gates/NAND.hpp>
#include <iostream>
#include "C4011.hpp"

C4011::C4011(const std::string &name) {
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

  nts::IComponent	*FirstNAND = new NAND();
  this->SetLink(1, *FirstNAND, 1);
  this->SetLink(2, *FirstNAND, 2);
  this->SetLink(3, *FirstNAND, 3);
  this->_innerCircuit.push_back(FirstNAND);

  nts::IComponent	*SecondNAND = new NAND();
  this->SetLink(4, *SecondNAND, 3);
  this->SetLink(5, *SecondNAND, 2);
  this->SetLink(6, *SecondNAND, 1);
  this->_innerCircuit.push_back(SecondNAND);

  nts::IComponent	*ThirdNAND = new NAND();
  this->SetLink(8, *ThirdNAND, 1);
  this->SetLink(9, *ThirdNAND, 2);
  this->SetLink(10, *ThirdNAND, 3);
  this->_innerCircuit.push_back(ThirdNAND);

  nts::IComponent	*FourthNAND = new NAND();
  this->SetLink(11, *FourthNAND, 3);
  this->SetLink(12, *FourthNAND, 2);
  this->SetLink(13, *FourthNAND, 1);
  this->_innerCircuit.push_back(FourthNAND);

  for (std::vector<Pin *>::iterator it = this->_pins.begin() ; it != this->_pins.end() ; ++it) {
    (*it)->setLinkState(false);
  }
}

C4011::~C4011() {
}