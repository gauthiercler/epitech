/*
** Paladin.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex03/Paladin.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 17:14:52 2017 Gauthier CLER
** Last update Thu Jan 12 17:14:52 2017 Gauthier CLER
*/


#include <iostream>
#include "Paladin.hh"

Paladin::Paladin(const std::string &name, int level) : Character(name, level), Warrior(name, level), Priest(name, level){
  this->setStrength(9);
  this->setStamina(10);
  this->setIntelligence(10);
  this->setSpirit(10);
  this->setAgility(2);
  std::cout << "the light falls on " << this->getName() << std::endl;
}

Paladin::~Paladin() {

}

int Paladin::CloseAttack() {
  return Warrior::CloseAttack();
}

void Paladin::Heal() {
  Priest::Heal();
}

void Paladin::RestorePower() {
  Character::RestorePower();
}

int Paladin::RangeAttack() {
  return Priest::RangeAttack();
}

int Paladin::Intercept() {
  return Warrior::RangeAttack();
}


