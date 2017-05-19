/*
** PowerFist.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/PowerFist.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:49:28 2017 Gauthier CLER
** Last update Fri Jan 13 11:49:28 2017 Gauthier CLER
*/


#include <iostream>
#include "PowerFist.hh"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50){

}

PowerFist::~PowerFist() {

}

void PowerFist::attack() const{
  std::cout << "* pschhh... SBAM! *" << std::endl;
}
