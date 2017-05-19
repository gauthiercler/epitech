/*
** Box.cpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Classes/Box.cpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 14:32:36 2017 Antoine FORET
** Last update Sat Jan 14 14:32:36 2017 Antoine FORET
*/

#include "Box.hpp"

Box::Box() : AWrap("Box", true, true), _open(false) {
}

Box::Box(const Box &box) : AWrap(box.getName(), box.isWrappable(), box.canWrap()), _open(box.isOpen()){
}

Box::~Box() {
}

Box &Box::operator=(const Box &box) {
  if (this != &box) {
    AWrap::operator=(box);
    this->setOpen(box.isOpen());
  }
  return *this;
}

bool Box::isOpen() const {
  return this->_open;
}

void Box::closeMe() {
  this->setOpen(false);
}

void Box::setOpen(bool open) {
  this->_open = open;
}

bool Box::wrapMeThat(AObject *object) {
  return !this->isOpen() && AWrap::wrapMeThat(object);
}

AObject *Box::clone() const {
  return new Box(*this);
}
