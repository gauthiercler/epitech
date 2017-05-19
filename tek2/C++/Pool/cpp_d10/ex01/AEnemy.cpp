/*
** AEnemy.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/AEnemy.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:48:58 2017 Gauthier CLER
** Last update Fri Jan 13 11:48:58 2017 Gauthier CLER
*/


#include "AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const &type): _hp(hp), _type(type) {

}

AEnemy::~AEnemy() {

}

std::string const AEnemy::getType() const {
  return this->_type;
}

int AEnemy::getHP() const {
  return this->_hp;
}

void AEnemy::takeDamage(int damage) {
  if (damage > 0){
    this->setHP(this->getHP() - damage);
  }
}

void AEnemy::setHP(int hp) {
  this->_hp = hp;
}
