/*
** RadScorpion.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/RadScorpion.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:49:39 2017 Gauthier CLER
** Last update Fri Jan 13 11:49:40 2017 Gauthier CLER
*/


#include <iostream>
#include "RadScorpion.hh"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion"){
  std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion() {
  std::cout << "* SPROTCH *" << std::endl;
}
