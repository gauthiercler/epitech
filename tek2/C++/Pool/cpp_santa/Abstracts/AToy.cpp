/*
** AToy.cpp for cpp_santa in /home/rubysh/Work/Repositories/Epitech/SecondYear/Pool/cpp_santa/Abstracts/AToy.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jan 14 14:02:20 2017 Anas Buyumad
** Last update Sat Jan 14 14:02:20 2017 Anas Buyumad
*/

#include <iostream>
#include "AToy.hpp"

AToy::AToy(const std::string &name) : AObject(name, true, false) {

}

AToy::AToy(const AToy &toy) : AObject(toy.getName(), toy.isWrappable(), toy.canWrap()) {

}

AToy::~AToy() {

}

AToy &AToy::operator=(const AToy &toy) {
  this->_name = toy.getName();
  this->_taken = false;
  return *this;
}
