/*
** AComponent.cpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/AComponent.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Feb 03 15:52:42 2017 Anas Buyumad
** Last update Fri Feb 03 15:52:42 2017 Anas Buyumad
*/

#include <sources/classes/errors/Error.hpp>
#include <sources/classes/misc/Misc.hpp>
#include "AComponent.hpp"

void nts::AComponent::setName(std::string name) {
  this->_name = name;
}


void nts::AComponent::setType(nts::AComponent::ComponentType type) {
  this->_type = type;
}

void nts::AComponent::setNbPins(size_t amount) {
  this->_nbPins = amount;
}

std::string nts::AComponent::getName(void) const {
  return this->_name;
}

nts::AComponent::ComponentType nts::AComponent::getType(void) const {
  return this->_type;
}

size_t nts::AComponent::getNbPins() const {
  return this->_nbPins;
}

Pin *nts::AComponent::getPinAt(size_t index) const {
  return this->_pins.at(index - 1);
}

bool nts::AComponent::CheckPinInRange(size_t PinsAmount, size_t PinNumber) {
  if (PinNumber < 1 || PinNumber > PinsAmount) {
    throw nts::Error("Pin out of range");
    // throw;
    return false;
  }
  return true;
}

bool nts::AComponent::CheckDupeLink(std::vector<std::pair<nts::IComponent*, size_t>*> LinkList, nts::IComponent *component, size_t pin_num) {
  for (std::vector<std::pair<nts::IComponent*,size_t>*>::iterator it = LinkList.begin() ;
       it != LinkList.end() ; ++it) {
    if ((*it)->first == component && (*it)->second == pin_num) {
      throw nts::Error("Link already exists");
      // throw;
      return true;
    }
  }
  return false;
}

nts::Tristate
nts::AComponent::ComputeListValue(std::vector<nts::Tristate> computeList) {
  nts::Tristate 	Eval = nts::Tristate::UNDEFINED;

  for (std::vector<nts::Tristate>::iterator it = computeList.begin() ;
    it != computeList.end() ; ++it) {
    if (Eval == nts::Tristate::UNDEFINED && *it != nts::Tristate::UNDEFINED) {
      Eval = *it;
    }
    if (*it != nts::Tristate::UNDEFINED && *it != Eval) {
      return nts::Tristate::UNDEFINED;
    }
  }
  return Eval;
}

nts::Tristate nts::AComponent::Compute(size_t pin_num_this) {
  nts::AComponent::CheckPinInRange(this->getNbPins(), pin_num_this);
  return this->getPinAt(pin_num_this)->Compute();
}

void nts::AComponent::SetLink(size_t pin_num_this, nts::IComponent &component,
			      size_t pin_num_target) {
  nts::AComponent::CheckPinInRange(this->getNbPins(), pin_num_this);
  nts::AComponent::CheckPinInRange(static_cast<nts::AComponent *>(&component)->getNbPins(), pin_num_target);
  this->getPinAt(pin_num_this)->setComponentLink(&component, pin_num_target);
  static_cast<nts::AComponent *>(&component)->getPinAt(pin_num_target)->setComponentLink(this, pin_num_this);
}

void nts::AComponent::Dump(void) const {
  std::cout << std::endl << "====================" << std::endl;
  std::cout << "Component : " << this->getName() << std::endl;
  for (size_t it = 1 ; it <= this->getNbPins() ; it++) {
    std::cout << "Pin " << it << " : " << std::endl;
    this->getPinAt(it)->Dump();
  }
}

nts::AComponent::~AComponent() {
  nts::Misc::deleteVector(&this->_pins);
  nts::Misc::deleteVector(&this->_innerCircuit);
}
