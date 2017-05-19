/*
** Lime.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex01/Lime.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 12:04:33 2017 Gauthier CLER
** Last update Tue Jan 17 12:04:34 2017 Gauthier CLER
*/

#include "Lime.h"

Lime::Lime() {
  this->setName("lime");
  this->setVitamins(2);
}

Lime::~Lime() {

}

std::string Lime::getName() const {
  return this->_name;
}
