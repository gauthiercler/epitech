/*
** AssaultTerminator.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex02/AssaultTerminator.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 14:36:24 2017 Gauthier CLER
** Last update Fri Jan 13 14:36:24 2017 Gauthier CLER
*/

#include <clocale>
#include <iostream>
#include "AssaultTerminator.hh"

AssaultTerminator::AssaultTerminator() {
  std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator() {
  std::cout << "I'll be back ..." << std::endl;
}

AssaultTerminator *AssaultTerminator::clone() const {
  AssaultTerminator	*marine;

  marine = new AssaultTerminator;
  return marine;
}

void AssaultTerminator::battleCry() const {
  std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void AssaultTerminator::rangedAttack() const {
  std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const {
  std::cout << "* attacks with chainfists *" << std::endl;
}
