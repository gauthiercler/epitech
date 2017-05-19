/*
** Borg.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07m/ex01/Borg.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 11:20:51 2017 Gauthier CLER
** Last update Tue Jan 10 11:20:53 2017 Gauthier CLER
*/

#include <iostream>
#include "Borg.hh"

Borg::Ship::Ship(int weaponFrequency, short repair) {
  this->_side = 300;
  this->_maxWarp = 9;
  this->_core = NULL;
  this->_home = UNICOMPLEX;
  this->_shield = 100;
  this->_location = this->_home;
  this->_weaponFrequency = weaponFrequency;
  this->_repair = repair;
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship() {

}

void Borg::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
}

void Borg::Ship::checkCore() {
  std::cout << ((this->_core->checkReactor()->isStable()) ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}

bool Borg::Ship::move(int warp, Destination d) {
  if (warp < this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()){
    this->_location = d;
    return true;
  }
  return false;
}

bool Borg::Ship::move(int warp) {
  if (warp < this->_maxWarp && this->_core->checkReactor()->isStable()){
    this->_location = this->_home;
    return true;
  }
  return false;
}

bool Borg::Ship::move(Destination d) {
  if (d != this->_location && this->_core->checkReactor()->isStable()){
    this->_location = d;
    return true;
  }
  return false;
}

bool Borg::Ship::move() {
  if (this->_core->checkReactor()->isStable()){
    this->_location = this->_home;
    return true;
  }
  return false;
}

int Borg::Ship::getShield() {
  return this->_shield;
}

void Borg::Ship::setShield(int shield) {
  this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency() {
  return this->_weaponFrequency;
}

void Borg::Ship::setWeaponFrequency(int frequency) {
  this->_weaponFrequency = frequency;
}

short Borg::Ship::getRepair() {
  return this->_repair;
}

void Borg::Ship::setRepair(short repair) {
  this->_repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *ship) {
  ship->setShield(ship->getShield() - this->_weaponFrequency);
  std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *ship) {
  ship->getCore()->checkReactor()->setStability(false);
  std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::repair() {
  if (this->_repair > 0){
    this->_shield = 100;
    std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
  }else{
    std::cout << "Energy cells depleted, shield weakening." << std::endl;
  }

}
