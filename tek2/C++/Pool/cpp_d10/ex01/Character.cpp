/*
** Character.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/Character.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:49:13 2017 Gauthier CLER
** Last update Fri Jan 13 11:49:14 2017 Gauthier CLER
*/


#include <iostream>
#include "Character.hh"

Character::Character(std::string const &name) :_name(name), _actionPoints(40), _weapon(NULL){

}

Character::~Character() {

}

void Character::recoverAP() {
  this->setActionPoints(this->getActionPoints() + 10);
  if (this->getActionPoints() > 40){
    this->setActionPoints(40);
  }
}

void Character::equip(AWeapon *weapon) {
  this->_weapon = weapon;
}

void Character::attack(AEnemy *enemy) {
  if (this->getWeapon()){
    if (this->getActionPoints() >= this->getWeapon()->getAPCost()){
      std::cout << this->getName() <<" attacks " << enemy->getType() << " with a " << this->getWeapon()->getName() << std::endl;
      this->getWeapon()->attack();
      this->setActionPoints(this->getActionPoints() - this->getWeapon()->getAPCost());
      enemy->takeDamage(this->_weapon->getDamage());
      if (enemy->getHP() < 0){
	delete enemy;
      }
    }
  }
}

std::string const Character::getName() const {
  return this->_name;
}

int Character::getActionPoints() const {
  return this->_actionPoints;
}

void Character::setActionPoints(int actionPoints) {
  this->_actionPoints = actionPoints;
}

AWeapon *Character::getWeapon() const{
  return this->_weapon;
}

std::ostream & operator<<(std::ostream & stream, Character const &character){
  if (character.getWeapon()){
    stream << character.getName() << " has " << character.getActionPoints() << " AP and wields a " << character.getWeapon()->getName() << std::endl;
  }else{
    stream << character.getName() << " has " << character.getActionPoints() << " AP and is unarmed" << std::endl;
  }
  return stream;
}
