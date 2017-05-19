/*
** FULL_ADDER.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/FULL_ADDER.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Feb 22 14:42:42 2017 Anas Buyumad
** Last update Wed Feb 22 14:42:42 2017 Anas Buyumad
*/

#include <sources/classes/components/gates/XOR.hpp>
#include <sources/classes/components/gates/AND.hpp>
#include <sources/classes/components/gates/OR.hpp>
#include "FULL_ADDER.hpp"

FULL_ADDER::FULL_ADDER(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::CHIPSET);
  this->setNbPins(5);

  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 1, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 2, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 3, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 4, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 5, true));

  nts::IComponent	*FirstXOR = new XOR();
  nts::IComponent	*SecondXOR = new XOR();
  nts::IComponent	*FirstAND = new AND();
  nts::IComponent	*SecondAND = new AND();
  nts::IComponent	*FirstOR = new OR();

  this->SetLink(1, *FirstXOR, 1);
  this->SetLink(2, *FirstXOR, 2);
  this->SetLink(1, *FirstAND, 1);
  this->SetLink(2, *FirstAND, 2);
  this->SetLink(3, *SecondAND, 1);

  FirstXOR->SetLink(3, *SecondAND, 2);
  FirstXOR->SetLink(3, *SecondXOR, 1);
  this->SetLink(3, *SecondXOR, 2);

  SecondAND->SetLink(3, *FirstOR, 1);
  FirstAND->SetLink(3, *FirstOR, 2);

  this->SetLink(4, *FirstOR, 3);
  this->SetLink(5, *SecondXOR, 3);

  this->_innerCircuit.push_back(FirstXOR);
  this->_innerCircuit.push_back(SecondXOR);
  this->_innerCircuit.push_back(FirstAND);
  this->_innerCircuit.push_back(SecondAND);
  this->_innerCircuit.push_back(FirstOR);

  for (std::vector<Pin *>::iterator it = this->_pins.begin() ; it != this->_pins.end() ; ++it) {
    (*it)->setLinkState(false);
  }
}

FULL_ADDER::~FULL_ADDER() {
}
