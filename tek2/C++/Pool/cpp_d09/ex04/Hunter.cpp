/*
** Hunter.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex04/Hunter.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 18:41:19 2017 Gauthier CLER
** Last update Thu Jan 12 18:41:19 2017 Gauthier CLER
*/


#include <iostream>
#include "Hunter.hh"

Hunter::Hunter(const std::string &name, int level) : Character(name, level), _weapon("sword"){
  this->setStrength(9);
  this->setStamina(9);
  this->setIntelligence(5);
  this->setSpirit(6);
  this->setAgility(24);
  std::cout << "I'm " << this->getName() << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
  std::cout << this->getName() << " is born from a tree" << std::endl;
}

Hunter::~Hunter() {

}

int Hunter::CloseAttack() {
  if (this->getPower() < 30){
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }
  this->setPower(this->getPower() - 30);
  std::cout << this->getName() << " strikes with his " << this->getWeapon() << std::endl;
  return 20 + this->getStrength();
}

const std::string Hunter::getWeapon() const{
  return this->_weapon;
}

int Hunter::RangeAttack() {
  if (this->getPower() < 25){
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }
  this->setPower(this->getPower() - 25);
  std::cout << this->getName() << " uses his bow" << std::endl;
  return 20 + this->getAgility();
}

void Hunter::RestorePower() {
  this->setPower(100);
  std::cout << this->getName() << " meditates" << std::endl;
}