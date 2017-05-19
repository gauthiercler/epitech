/*
** Character.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex00/Character.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 12:09:41 2017 Gauthier CLER
** Last update Thu Jan 12 12:09:48 2017 Gauthier CLER
*/

#include <iostream>
#include "Character.hh"

Character::Character(const std::string &name, int level) : _name(name), _level(level), _pv(100), _power(100), _strength(5),
							   _stamina(5), _intelligence(5), _spirit(5), _agility(5), Range(CLOSE){
  std::cout << this->getName() << " Created" << std::endl;
}

Character::Character(Character const &other) : _name(other.getName()), _level(other.getLvl()), _pv(other.getPv()), _power(other.getPower()),
					       _strength(other.getStrength()), _stamina(other.getStamina()), _intelligence(other.getIntelligence()),
					       _spirit(other.getSpirit()), _agility(other.getAgility()), Range(other.getRange()){
  std::cout << this->getName() << " Created" << std::endl;
}

Character::~Character() {

}

const std::string &Character::getName() const{
  return this->_name;
}

int Character::getLvl() const{
  return this->_level;
}

int Character::getPv() const{
  return this->_pv;
}

int Character::getPower() const{
  return this->_power;
}

void Character::setLvl(const int &lvl) {
  this->_level = lvl;
}

void Character::setPv(const int &pv) {
  this->_pv = pv;
}

void Character::setPower(const int &power) {
  this->_power = power;
}

void Character::setName(const std::string &name) {
  this->_name = name;
}

Character &Character::operator=(Character const &other){
  this->setName(other.getName());
  this->setLvl(other.getLvl());
  this->setPower(other.getPower());
  this->setPv(other.getPv());
  this->setAgility(other.getAgility());
  this->setStrength(other.getStrength());
  this->setIntelligence(other.getIntelligence());
  this->setStamina(other.getStamina());
  this->setSpirit(other.getSpirit());
  return *this;
}

int Character::getStrength() const {
  return  this->_strength;
}

int Character::getStamina() const {
  return this->_stamina;
}

int Character::getIntelligence() const {
  return this->_intelligence;
}

int Character::getSpirit() const {
  return this->_spirit;
}

int Character::getAgility() const {
  return this->_agility;
}

void Character::setStrength(const int &strength) {
  this->_strength = strength;
}

void Character::setStamina(const int &stamina) {
  this->_stamina = stamina;
}

void Character::setIntelligence(const int &intelligence) {
  this->_intelligence = intelligence;
}

void Character::setSpirit(const int &spirit) {
  this->_spirit = spirit;
}

void Character::setAgility(const int &agility) {
  this->_agility = agility;
}

int Character::CloseAttack() {
  if (this->getPower() < 10){
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }
  this->setPower(this->getPower() - 10);
  std::cout << this->getName() << " strikes with a wood stick" << std::endl;
  return 10 + this->getStrength();
}

int Character::RangeAttack() {
  if (this->getPower() < 10){
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }
  this->setPower(this->getPower() - 10);
  std::cout << this->getName() << " launches a stone" << std::endl;
  return 5 + this->getStrength();
}

void Character::TakeDamage(const int &_damage) {
  if (this->getPv() > 0){
    this->setPv(this->getPv() - _damage);
  }
  if (this->getPv() <= 0)
    std::cout << this->getName() << " out of combat" << std::endl;
  else
    std::cout << this->getName() << " takes " << _damage << " damage" << std::endl;
}

void Character::Heal() {
  this->setPv(this->getPv() + 50);
  if (this->getPv() > 100)
    this->setPv(100);
  std::cout << this->getName() << " takes a potion" << std::endl;
}

void Character::RestorePower() {
  this->setPower(100);
  std::cout << this->getName() << " eats" << std::endl;
}

Character::AttackRange Character::getRange() const {
  return this->Range;
}

void Character::setRange(AttackRange const &range) {
  this->Range = range;
}


