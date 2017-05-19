/*
** C4069.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4069.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:41:37 2017 Anas Buyumad
** Last update Fri Jan 27 20:41:38 2017 Anas Buyumad
*/

#include <sources/classes/components/gates/NOT.hpp>
#include "C4069.hpp"

C4069::C4069(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::CHIPSET);
  this->setNbPins(14);

  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 1, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 2, true));

  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 3, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 4, true));

  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 5, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 6, true));

  this->_pins.push_back(new Pin(Pin::IGNORED, NULL, 7, true));

  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 8, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 9, true));

  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 10, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 11, true));

  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 12, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 13, true));

  this->_pins.push_back(new Pin(Pin::IGNORED, NULL, 14, true));

  nts::IComponent	*FirstNOT = new NOT();
  this->SetLink(1, *FirstNOT, 1);
  this->SetLink(2, *FirstNOT, 2);
  this->_innerCircuit.push_back(FirstNOT);

  nts::IComponent	*SecondNOT = new NOT();
  this->SetLink(3, *SecondNOT, 1);
  this->SetLink(4, *SecondNOT, 2);
  this->_innerCircuit.push_back(SecondNOT);

  nts::IComponent	*ThirdNOT = new NOT();
  this->SetLink(5, *ThirdNOT, 1);
  this->SetLink(6, *ThirdNOT, 2);
  this->_innerCircuit.push_back(ThirdNOT);

  nts::IComponent	*FourthNOT = new NOT();
  this->SetLink(8, *FourthNOT, 2);
  this->SetLink(9, *FourthNOT, 1);
  this->_innerCircuit.push_back(FourthNOT);

  nts::IComponent	*FifthNOT = new NOT();
  this->SetLink(10, *FifthNOT, 2);
  this->SetLink(11, *FifthNOT, 1);
  this->_innerCircuit.push_back(FifthNOT);

  nts::IComponent	*SixthNOT = new NOT();
  this->SetLink(12, *SixthNOT, 2);
  this->SetLink(13, *SixthNOT, 1);
  this->_innerCircuit.push_back(SixthNOT);

  for (std::vector<Pin *>::iterator it = this->_pins.begin() ; it != this->_pins.end() ; ++it) {
    (*it)->setLinkState(false);
  }
}

C4069::~C4069() {

}
