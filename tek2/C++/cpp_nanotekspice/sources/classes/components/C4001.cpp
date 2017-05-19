/*
** C4001.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4001.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:36:33 2017 Anas Buyumad
** Last update Fri Jan 27 20:36:34 2017 Anas Buyumad
*/

#include <sources/classes/components/gates/NOR.hpp>
#include <iostream>
#include "C4001.hpp"

C4001::C4001(const std::string &name) {
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

  nts::IComponent	*FirstNOR = new NOR();
  this->SetLink(1, *FirstNOR, 1);
  this->SetLink(2, *FirstNOR, 2);
  this->SetLink(3, *FirstNOR, 3);
  this->_innerCircuit.push_back(FirstNOR);

  nts::IComponent	*SecondNOR = new NOR();
  this->SetLink(4, *SecondNOR, 3);
  this->SetLink(5, *SecondNOR, 2);
  this->SetLink(6, *SecondNOR, 1);
  this->_innerCircuit.push_back(SecondNOR);

  nts::IComponent	*ThirdNOR = new NOR();
  this->SetLink(8, *ThirdNOR, 1);
  this->SetLink(9, *ThirdNOR, 2);
  this->SetLink(10, *ThirdNOR, 3);
  this->_innerCircuit.push_back(ThirdNOR);

  nts::IComponent	*FourthNOR = new NOR();
  this->SetLink(11, *FourthNOR, 3);
  this->SetLink(12, *FourthNOR, 2);
  this->SetLink(13, *FourthNOR, 1);
  this->_innerCircuit.push_back(FourthNOR);

  for (std::vector<Pin *>::iterator it = this->_pins.begin() ; it != this->_pins.end() ; ++it) {
    (*it)->setLinkState(false);
  }
}

C4001::~C4001() {
}
