/*
** PlasmaRifle.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/PlasmaRifle.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:49:19 2017 Gauthier CLER
** Last update Fri Jan 13 11:49:19 2017 Gauthier CLER
*/


#include <iostream>
#include "PlasmaRifle.hh"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21){

}


PlasmaRifle::~PlasmaRifle() {

}

void PlasmaRifle::attack() const{
  std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
