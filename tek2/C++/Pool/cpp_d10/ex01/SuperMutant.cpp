/*
** SuperMutant.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/SuperMutant.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:49:50 2017 Gauthier CLER
** Last update Fri Jan 13 11:49:51 2017 Gauthier CLER
*/


#include <iostream>
#include "SuperMutant.hh"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant"){
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant() {
  std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int damage) {
  AEnemy::takeDamage(damage - 3);
}
