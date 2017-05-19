/*
** C4030.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4030.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:40:20 2017 Anas Buyumad
** Last update Fri Jan 27 20:40:20 2017 Anas Buyumad
*/

#include <sources/classes/components/gates/XOR.hpp>
#include <iostream>
#include "C4030.hpp"

C4030::C4030(const std::string &name) {
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

  nts::IComponent	*FirstXOR = new XOR();
  this->SetLink(1, *FirstXOR, 1);
  this->SetLink(2, *FirstXOR, 2);
  this->SetLink(3, *FirstXOR, 3);
  this->_innerCircuit.push_back(FirstXOR);

  nts::IComponent	*SecondXOR = new XOR();
  this->SetLink(4, *SecondXOR, 3);
  this->SetLink(5, *SecondXOR, 2);
  this->SetLink(6, *SecondXOR, 1);
  this->_innerCircuit.push_back(SecondXOR);

  nts::IComponent	*ThirdXOR = new XOR();
  this->SetLink(8, *ThirdXOR, 1);
  this->SetLink(9, *ThirdXOR, 2);
  this->SetLink(10, *ThirdXOR, 3);
  this->_innerCircuit.push_back(ThirdXOR);

  nts::IComponent	*FourthXOR = new XOR();
  this->SetLink(11, *FourthXOR, 3);
  this->SetLink(12, *FourthXOR, 2);
  this->SetLink(13, *FourthXOR, 1);
  this->_innerCircuit.push_back(FourthXOR);

  for (std::vector<Pin *>::iterator it = this->_pins.begin() ; it != this->_pins.end() ; ++it) {
    (*it)->setLinkState(false);
  }
}

C4030::~C4030() {
}