/*
** C4013.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4013.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:38:25 2017 Anas Buyumad
** Last update Fri Jan 27 20:38:25 2017 Anas Buyumad
*/

#include "C4013.hpp"
#include "D_FLIP_FLOP.hpp"

C4013::C4013(const std::string &name) {
  this->setName(name);
  this->setType(nts::AComponent::CHIPSET);
  this->setNbPins(14);

  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 1, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 2, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 3, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 4, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 5, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 6, true));

  this->_pins.push_back(new Pin(Pin::IGNORED, NULL, 7, true));

  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 8, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 9, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 10, true));
  this->_pins.push_back(new Pin(Pin::INPUT, NULL, 11, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 12, true));
  this->_pins.push_back(new Pin(Pin::OUTPUT, NULL, 13, true));

  this->_pins.push_back(new Pin(Pin::IGNORED, NULL, 14, true));

  nts::IComponent		*FirstFlipFlop = new D_FLIP_FLOP();
  nts::IComponent		*SecondFlipFlop = new D_FLIP_FLOP();

  // First FlipFlop
  this->SetLink(1, *FirstFlipFlop, 1);
  this->SetLink(2, *FirstFlipFlop, 2);
  this->SetLink(3, *FirstFlipFlop, 3);
  this->SetLink(4, *FirstFlipFlop, 4);
  this->SetLink(5, *FirstFlipFlop, 5);
  this->SetLink(6, *FirstFlipFlop, 6);

  // Second FlipFlop
  this->SetLink(8, *SecondFlipFlop, 1);
  this->SetLink(9, *SecondFlipFlop, 2);
  this->SetLink(10, *SecondFlipFlop, 3);
  this->SetLink(11, *SecondFlipFlop, 4);
  this->SetLink(12, *SecondFlipFlop, 5);
  this->SetLink(13, *SecondFlipFlop, 6);

  this->_innerCircuit.push_back(FirstFlipFlop);
  this->_innerCircuit.push_back(SecondFlipFlop);

  for (std::vector<Pin *>::iterator it = this->_pins.begin() ; it != this->_pins.end() ; ++it) {
    (*it)->setLinkState(false);
  }
}

C4013::~C4013() {

}