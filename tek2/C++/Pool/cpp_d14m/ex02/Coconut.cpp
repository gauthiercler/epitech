/*
** Coconut.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex02/Coconut.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 12:39:57 2017 Gauthier CLER
** Last update Tue Jan 17 12:39:57 2017 Gauthier CLER
*/

#include "Coconut.h"

Coconut::Coconut() {
  this->setName("coconut");
  this->setVitamins(15);
}

Coconut::~Coconut() {

}

std::string Coconut::getName() const {
  return this->_name;
}
