/*
** Lemon.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex00/Lemon.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 10:20:13 2017 Gauthier CLER
** Last update Tue Jan 17 10:20:13 2017 Gauthier CLER
*/

#include "Lemon.h"

Lemon::Lemon(){
  this->setName("lemon");
  this->setVitamins(3);
}

Lemon::~Lemon() {

}

std::string Lemon::getName() const{
  return this->_name;
}
