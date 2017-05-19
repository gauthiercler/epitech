/*
** C4081.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4081.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:42:40 2017 Anas Buyumad
** Last update Fri Jan 27 20:42:40 2017 Anas Buyumad
*/

#include <sources/classes/components/gates/AND.hpp>
#include <iostream>
#include "C4081.hpp"

C4081::C4081(const std::string &name) {
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

  nts::IComponent	*FirstAND = new AND();
  this->SetLink(1, *FirstAND, 1);
  this->SetLink(2, *FirstAND, 2);
  this->SetLink(3, *FirstAND, 3);
  this->_innerCircuit.push_back(FirstAND);

  nts::IComponent	*SecondAND = new AND();
  this->SetLink(4, *SecondAND, 3);
  this->SetLink(5, *SecondAND, 2);
  this->SetLink(6, *SecondAND, 1);
  this->_innerCircuit.push_back(SecondAND);

  nts::IComponent	*ThirdAND = new AND();
  this->SetLink(8, *ThirdAND, 1);
  this->SetLink(9, *ThirdAND, 2);
  this->SetLink(10, *ThirdAND, 3);
  this->_innerCircuit.push_back(ThirdAND);

  nts::IComponent	*FourthAND = new AND();
  this->SetLink(11, *FourthAND, 3);
  this->SetLink(12, *FourthAND, 2);
  this->SetLink(13, *FourthAND, 1);
  this->_innerCircuit.push_back(FourthAND);

  for (std::vector<Pin *>::iterator it = this->_pins.begin() ; it != this->_pins.end() ; ++it) {
    (*it)->setLinkState(false);
  }
}

C4081::~C4081() {
}