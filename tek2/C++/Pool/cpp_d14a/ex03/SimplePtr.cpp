/*
** SimplePtr.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14a/ex03/SimplePtr.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 20:37:43 2017 Gauthier CLER
** Last update Tue Jan 17 20:37:43 2017 Gauthier CLER
*/

#include <clocale>
#include <iostream>
#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr) {
  this->_rawPtr = rawPtr;
}

SimplePtr::~SimplePtr() {
  if (this->_rawPtr)
    delete this->_rawPtr;
}

BaseComponent *SimplePtr::get() const {
  return this->_rawPtr;
}
