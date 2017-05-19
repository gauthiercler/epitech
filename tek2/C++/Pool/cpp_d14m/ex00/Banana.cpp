/*
** Banana.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex00/Banana.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 10:20:01 2017 Gauthier CLER
** Last update Tue Jan 17 10:20:01 2017 Gauthier CLER
*/

#include "Banana.h"

Banana::Banana() {
  this->setName("banana");
  this->setVitamins(5);
}

Banana::~Banana() {

}

std::string Banana::getName() const{
  return this->_name;
}
