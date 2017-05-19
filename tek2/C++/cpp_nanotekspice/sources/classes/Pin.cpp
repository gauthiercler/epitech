/*
** Pin.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/Pin.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Jan 30 13:42:16 2017 Anas Buyumad
** Last update Mon Jan 30 13:42:16 2017 Anas Buyumad
*/

#include <iostream>
#include <sources/classes/misc/Misc.hpp>
#include "AComponent.hpp"

Pin::Pin(Pin::PinType Type,  nts::IComponent *motherboard, size_t index, bool border) : _type(Type), _value(nts::Tristate::UNDEFINED), _number(index), _border(border), _isLinked(false), _isLocked(false),  _motherboard(motherboard) {
}

Pin::~Pin() {
  nts::Misc::deleteVector(&this->_componentLinks);
}

Pin::PinType Pin::getType() const {
  return this->_type;
}

nts::Tristate Pin::getValue() const {
  return this->_value;
}

nts::IComponent *Pin::getMotherboard() const {
  return this->_motherboard;
}

size_t Pin::getMBnumber() const {
  return this->_number;
}

bool Pin::isLinked() const {
  return this->_isLinked;
}

bool Pin::isLocked() const {
  return this->_isLocked;
}

std::pair<nts::IComponent *, size_t> *Pin::getComponentLinkAt(size_t index) const {
  if ((index) && (index >= this->_componentLinks.size())) {
    return NULL;
  }
  return this->_componentLinks.at(index - 1);
}

void Pin::setType(Pin::PinType Type) {
  this->_type = Type;
}

void Pin::setValue(nts::Tristate value) {
  this->_value = value;
}

void Pin::setLinkState(bool state) {
  this->_isLinked = state;
}

void Pin::setLockState(bool state) {
  this->_isLocked = state;
}

void Pin::setComponentLink(nts::IComponent *component, size_t pin_num) {
  nts::AComponent::CheckDupeLink(this->_componentLinks, component, pin_num);
  std::pair<nts::IComponent*, size_t>	*linkPair = new std::pair<nts::IComponent*, size_t>(component, pin_num);
  this->_componentLinks.push_back(linkPair);
  this->setLinkState(true);
}

void Pin::Dump() const {
  for (std::vector<std::pair<nts::IComponent*,size_t>*>::const_iterator it = this->_componentLinks.begin();
  it != this->_componentLinks.end() ; ++it) {
    std::cout << "Link : " << static_cast<nts::AComponent *>((*it)->first)->getName() << " :: " << (*it)->second << std::endl;
  }
}

nts::Tristate Pin::Compute() {

  if (this->getType() == Pin::PinType::IGNORED)
    return nts::Tristate::UNDEFINED;
  this->setLockState(true);			// Locking pin.

  std::vector<nts::Tristate>	computeList;	// Vector of computed pins values.
  Pin				*LinkedPin;	// Temp Pin.

  // Check if callback, if so, add it in the value list.
  if (this->_motherboard) {
    nts::Tristate callback = this->_motherboard->Compute(this->_number);
    if (callback == nts::Tristate::UNDEFINED) {
      callback = this->getValue();
    }
    computeList.push_back(callback);
  }
  else if (this->getType() == Pin::OUTPUT && this->_motherboard == NULL && !this->_border) {
    computeList.push_back(this->_value); 	// If type is output, we add its value to the list.
  }

  // Loop on linked pins.
  for (std::vector<std::pair<nts::IComponent *, size_t> *>::iterator it = this->_componentLinks.begin() ;
       it != this->_componentLinks.end() ; ++it) {
    LinkedPin = static_cast<nts::AComponent *>((*it)->first)->getPinAt((*it)->second);
    if (!(LinkedPin->isLocked()) && (LinkedPin->getType() != Pin::PinType::INPUT || LinkedPin->_border)) {
      computeList.push_back(LinkedPin->Compute());
    }
  }
  
  this->setLockState(false);			// Unlocking pin.
  // Store Value in pin.
  this->setValue(nts::AComponent::ComputeListValue(computeList));
  return this->getValue();
}