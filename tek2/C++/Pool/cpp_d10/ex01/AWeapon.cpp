/*
** AWeapon.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/AWeapon.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:49:06 2017 Gauthier CLER
** Last update Fri Jan 13 11:49:06 2017 Gauthier CLER
*/


#include "AWeapon.hh"

AWeapon::AWeapon(std::string const &name, int apCost, int damage) : _name(name), _apCost(apCost), _damage(damage){
}

AWeapon::~AWeapon() {

}

std::string const AWeapon::getName() const {
  return this->_name;
}

int AWeapon::getAPCost() const {
  return this->_apCost;
}

int AWeapon::getDamage() const {
  return this->_damage;
}

void AWeapon::setAPCost(int apCost) {
  this->_apCost = apCost;
}

void AWeapon::setDamage(int damage) {
  this->_damage = damage;
}
