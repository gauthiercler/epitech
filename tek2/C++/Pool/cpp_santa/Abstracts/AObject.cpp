/*
** AObject.cpp for cpp_santa in /home/ventinc/epitech/piscine/cpp_santa/Abstracts/AObject.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Jan 14 14:03:20 2017 Vincent DUSAUTOIR
** Last update Sat Jan 14 14:03:24 2017 Vincent DUSAUTOIR
*/

#include "Abstracts/AObject.hpp"

AObject::AObject(const std::string &name, bool wrappable, bool canWrap): _name(name), _wrappable(wrappable), _canWrap(canWrap), _taken(false) {
}

AObject::AObject(const AObject &object): _name(object.getName()), _wrappable(object.isWrappable()), _canWrap(object.canWrap()), _taken(object.getTaken()) {

}

AObject::~AObject() {

}

const std::string &AObject::getName() const {
  return this->_name;
}

bool AObject::isWrappable() const {
  return this->_wrappable;
}

bool AObject::canWrap() const {
  return this->_canWrap;
}

bool AObject::getTaken() const {
  return this->_taken;
}

void AObject::setName(const std::string &name) {
  this->_name = name;
}

void AObject::setTaken(bool taken) {
  this->_taken = taken;
}

void AObject::setWrappable(bool wrappable) {
  this->_wrappable = wrappable;
}

void AObject::setCanWrap(bool canWrap) {
  this->_canWrap = canWrap;
}

AObject &AObject::operator=(const AObject &object) {
  this->setName(object.getName());
  this->setCanWrap(object.canWrap());
  this->setTaken(object.getTaken());
  this->setWrappable(object.getTaken());
  return *this;
}
