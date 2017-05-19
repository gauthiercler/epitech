/*
** AWrap.cpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Abstracts/AWrap.cpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 14:02:25 2017 Antoine FORET
** Last update Sat Jan 14 14:02:25 2017 Antoine FORET
*/

#include "AWrap.hpp"

AWrap::AWrap(const std::string name, bool wrappable, bool canWrap) : AObject(name, wrappable, canWrap), _content(NULL){
}

AWrap::AWrap(const AWrap &wrap) : AObject(wrap.getName(), wrap.isWrappable(), wrap.canWrap()), _content(NULL) {
  if (this->_content != NULL)
    this->_content = this->_content->clone();
}

AWrap::~AWrap() {
  if (this->_content != NULL)
    delete this->_content;
}

AWrap &AWrap::operator=(const AWrap &wrap) {
  if (this != &wrap)
  {
    AObject::operator=(wrap);
    if (this->_content != NULL)
      delete this->_content;
    if (wrap._content != NULL)
      this->_content = wrap._content->clone();
    else
      this->_content = NULL;
  }
  return *this;
}

bool AWrap::isTaken() {
  if (!this->getTaken()) {
    this->setTaken(true);
    return true;
  }
  return false;
}

AObject *AWrap::openMe() {
  AObject *object = this->_content;

  this->_content = NULL;
  return object;
}

bool AWrap::wrapMeThat(AObject *object) {
  if (this->_content != NULL)
    return false;
  this->_content = object;
  return true;
}

bool AWrap::isPut() {
  if (this->getTaken()) {
    this->setTaken(false);
    return true;
  }
  return false;
}
