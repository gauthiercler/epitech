/*
** Priest.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex02/Priest.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 16:16:07 2017 Gauthier CLER
** Last update Thu Jan 12 16:16:07 2017 Gauthier CLER
*/


#include <iostream>
#include "Priest.hh"

Priest::Priest(const std::string &name, int level) : Character(name, level), Mage(name, level){
  this->setStrength(4);
  this->setStamina(4);
  this->setIntelligence(42);
  this->setSpirit(21);
  this->setAgility(2);
  std::cout << this->getName() << " enters in the order" << std::endl;
}

Priest::~Priest() {

}

int Priest::CloseAttack() {
  if (this->getPower() < 10){
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }
  this->setPower(this->getPower() - 10);
  std::cout << this->getName() << " uses a spirit explosion" <<std::endl;
  return 10 + this->getSpirit();
}

int Priest::RangeAttack() {
  if (this->getPower() < 25){
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }
  this->setPower(this->getPower() - 25);
  std::cout << this->getName() << " launches a fire ball" << std::endl;
  return 20 + this->getSpirit();
}

void Priest::Heal() {
  if (this->getPower() < 10){
    std::cout << this->getName() << " out of power" << std::endl;
    return ;
  }
  this->setPower(this->getPower() - 10);
  this->setPv(this->getPv() + 70);
  if (this->getPv() > 100)
    this->setPv(100);
  std::cout << this->getName() << " casts a little heal spell" << std::endl;
}

void Priest::RestorePower() {
  Mage::RestorePower();
}


