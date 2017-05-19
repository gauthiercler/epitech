/*
** TacticalMarine.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex02/TacticalMarine.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 14:36:41 2017 Gauthier CLER
** Last update Fri Jan 13 14:36:41 2017 Gauthier CLER
*/


#include <clocale>
#include <iostream>
#include "TacticalMarine.hh"

TacticalMarine::TacticalMarine() {
  std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine() {
  std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine *TacticalMarine::clone() const {
  TacticalMarine	*marine;

  marine = new TacticalMarine;
  return marine;
}

void TacticalMarine::battleCry() const {
  std::cout << "For the holy PLOT !" << std::endl;
}

void TacticalMarine::rangedAttack() const {
  std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const {
  std::cout << "* attacks with chainsword *" << std::endl;
}
