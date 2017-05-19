/*
** Fruit.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex00/Fruit.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 10:20:05 2017 Gauthier CLER
** Last update Tue Jan 17 10:20:05 2017 Gauthier CLER
*/

#include "Fruit.h"

Fruit::Fruit(int vitamins) : _name(""), _vitamins(vitamins){

}

int Fruit::getVitamins() const {
  return this->_vitamins;
}

void Fruit::setVitamins(int vitamins) {
  this->_vitamins = vitamins;
}

void Fruit::setName(std::string name) {
  this->_name = name;
}

Fruit::~Fruit() {

}
