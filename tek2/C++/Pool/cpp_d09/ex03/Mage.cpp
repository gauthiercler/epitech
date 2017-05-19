/*
** Mage.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex02/Mage.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 16:16:07 2017 Gauthier CLER
** Last update Thu Jan 12 16:16:07 2017 Gauthier CLER
*/


#include <iostream>
#include "Mage.hh"

Mage::Mage(const std::string &name, int level) : Character(name, level){
  this->setStrength(6);
  this->setStamina(6);
  this->setIntelligence(12);
  this->setSpirit(11);
  this->setAgility(7);
  std::cout << this->getName() << " teleported" << std::endl;
}

Mage::~Mage() {

}

int Mage::CloseAttack() {
  if (this->getPower() < 10){
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }
  this->setPower(this->getPower() - 10);
  std::cout << this->getName() << " blinks" <<std::endl;
  this->setRange(RANGE);
  return 0;
}

int Mage::RangeAttack() {
  if (this->getPower() < 25){
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }
  this->setPower(this->getPower() - 25);
  std::cout << this->getName() << " launches a fire ball" << std::endl;
  return 20 + this->getSpirit();
}

void Mage::RestorePower() {
  this->setPower(this->getPower() + 50 + this->getIntelligence());
  if (this->getPower() > 100)
    this->setPower(100);
  std::cout << this->getName() << " takes a mana potion" << std::endl;
}
