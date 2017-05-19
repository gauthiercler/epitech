/*
** C4008.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4008.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:37:33 2017 Anas Buyumad
** Last update Fri Jan 27 20:37:33 2017 Anas Buyumad
*/

#include <sources/classes/components/FULL_ADDER.hpp>
#include "C4008.hpp"

C4008::C4008(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::CHIPSET);
  this->setNbPins(16);

  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 1, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 2, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 3, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 4, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 5, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 6, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 7, true));

  this->_pins.push_back(new Pin(Pin::IGNORED, NULL, 8, true));

  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 9, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 10, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 11, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 12, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 13, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 14, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 15, true));

  this->_pins.push_back(new Pin(Pin::IGNORED, NULL, 16, true));

  nts::IComponent	*FirstADDER = new FULL_ADDER();
  nts::IComponent	*SecondADDER = new FULL_ADDER();
  nts::IComponent	*ThirdADDER = new FULL_ADDER();
  nts::IComponent	*FourthADDER = new FULL_ADDER();

  // Carry in
  this->SetLink(9, *FirstADDER, 3);

  // First Adder
  this->SetLink(7, *FirstADDER, 1);
  this->SetLink(6, *FirstADDER, 2);
  this->SetLink(10, *FirstADDER, 5);

  // Carry out 1
  FirstADDER->SetLink(4, *SecondADDER, 3);

  // Second Adder
  this->SetLink(5, *SecondADDER, 1);
  this->SetLink(4, *SecondADDER, 2);
  this->SetLink(11, *SecondADDER, 5);

  // Carry out 2
  SecondADDER->SetLink(4, *ThirdADDER, 3);

  // Third Adder
  this->SetLink(3, *ThirdADDER, 1);
  this->SetLink(2, *ThirdADDER, 2);
  this->SetLink(12, *ThirdADDER, 5);

  // Carry out 3
  ThirdADDER->SetLink(4, *FourthADDER, 3);

  // Fourth Adder
  this->SetLink(1, *FourthADDER, 1);
  this->SetLink(15, *FourthADDER, 2);
  this->SetLink(13, *FourthADDER, 5);

  // Carry out
  this->SetLink(14, *FourthADDER, 4);

  this->_innerCircuit.push_back(FirstADDER);
  this->_innerCircuit.push_back(SecondADDER);
  this->_innerCircuit.push_back(ThirdADDER);
  this->_innerCircuit.push_back(FourthADDER);

  for (std::vector<Pin *>::iterator it = this->_pins.begin() ; it != this->_pins.end() ; ++it) {
    (*it)->setLinkState(false);
  }
}

C4008::~C4008() {

}
