/*
** Warrior.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex01/Warrior.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 15:01:58 2017 Gauthier CLER
** Last update Thu Jan 12 15:01:58 2017 Gauthier CLER
*/


#include <iostream>
#include "Warrior.hh"

Warrior::Warrior(const std::string &name, int level) : Character(name, level), _weapon(std::string("hammer")) {
  this->setStrength(12);
  this->setStamina(12);
  this->setIntelligence(6);
  this->setAgility(7);
  this->setIsRange(true);
  std::cout << "I'm " << this->getName() << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior() {

}

int Warrior::CloseAttack() {
  if (this->getPower() < 30){
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }
  this->setPower(this->getPower() - 30);
  std::cout << this->getName() << " strikes with his " << this->getWeapon() << std::endl;
  return 20 + this->getStrength();
}

const std::string Warrior::getWeapon() const{
  return this->_weapon;
}

int Warrior::RangeAttack() {
  if (this->getPower() < 10){
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }
  this->setPower(this->getPower() - 10);
  this->setRange(CLOSE);
  std::cout << this->getName() << " intercepts" << std::endl;
  return 0;
}

bool Warrior::getIsRange() const{
  return this->_isRange;
}

void Warrior::setIsRange(bool range) {
  this->_isRange = range;
}
