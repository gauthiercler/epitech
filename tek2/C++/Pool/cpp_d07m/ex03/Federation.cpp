/*
** Federation.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07m/ex00/Federation.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 10:19:51 2017 Gauthier CLER
** Last update Tue Jan 10 10:19:53 2017 Gauthier CLER
*/

#include <iostream>
#include "Federation.hh"
#include "Borg.hh"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name,
				  short maxWarp, int torpedo) {
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;
  this->_core = NULL;
  this->_home = EARTH;
  this->_location = this->_home;
  this->_shield = 100;
  this->_photonTorpedo = torpedo;

  std::cout << "The ship USS " << this->_name << " has been finished. It is "
	    << this->_length << " m in length and " << this->_width << " m in width. ";
  std::cout << "It can go to Warp " << this->_maxWarp << "!";
  std::cout << " Weapons are set: " << this->_photonTorpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::~Ship() {

}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
  std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore() {
  std::cout << "USS " << this->_name << ": The core is "
	    << ((this->_core->checkReactor()->isStable()) ? "stable" : "unstable")
	    << " at the time." << std::endl;
}

void
Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain) {
  this->_captain = captain;
  std::cout << this->_captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d) {
  if (warp < this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()){
    this->_location = d;
    return true;
  }
  return false;
}

bool Federation::Starfleet::Ship::move(int warp) {
  if (warp < this->_maxWarp && this->_core->checkReactor()->isStable()){
    this->_location = this->_home;
    return true;
  }
  return false;
}

bool Federation::Starfleet::Ship::move(Destination d) {
  if (d != this->_location && this->_core->checkReactor()->isStable()){
    this->_location = d;
    return true;
  }
  return false;
}

bool Federation::Starfleet::Ship::move() {
  if (this->_core->checkReactor()->isStable()){
    this->_location = this->_home;
    return true;
  }
  return false;
}

int Federation::Starfleet::Ship::getShield() {
  return this->_shield;
}

void Federation::Starfleet::Ship::setShield(int shield) {
  this->_shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo() {
  return this->_photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo) {
  this->_photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *ship) {
  if (this->_photonTorpedo == 0){
    std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
  }else{
    this->_photonTorpedo -= 1;
    ship->setShield(ship->getShield() - 50);
    std::count << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
  }
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship * ship) {
  if (this->_photonTorpedo == 0){
    std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
  }else if (torpedoes > this->_photonTorpedo){
    std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
  }else{
    this->_photonTorpedo -= torpedoes;
    ship->setShield(ship->getShield() - (50 * torpedoes));
    std::count << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
  }
}

Federation::Starfleet::Ship::Ship() {
  this->_length = 289;
  this->_width = 132;
  this->_name = "Entreprise";
  this->_maxWarp = 6;
  this->_core = NULL;
  this->_home = EARTH;
  this->_location = this->_home;
  this->_shield = 100;
  this->_photonTorpedo = 20;

  std::cout << "The ship USS " << this->_name << " has been finished. It is "
	    << this->_length << " m in length and " << this->_width << " m in width. ";
  std::cout << "It can go to Warp " << this->_maxWarp << "!";
  std::cout << " Weapons are set: " << this->_photonTorpedo << " torpedoes ready." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name) {
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = 1;
  this->_core = NULL;
  this->_home = VULCAN;
  this->_location = this->_home;
  std::cout << "The independant ship " << this->_name << " just finished its construction. It is "
	    << this->_length << " m in length and " << this->_width << " m in width."
	    << std::endl;
}

Federation::Ship::~Ship() {

}

void Federation::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
  std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore() {
  std::cout << this->_name << ": The core is "
	    << ((this->_core->checkReactor()->isStable()) ? "stable" : "unstable")
	    << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d) {
  if (warp < this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()){
    this->_location = d;
    return true;
  }
  return false;
}

bool Federation::Ship::move(int warp) {
  if (warp < this->_maxWarp && this->_core->checkReactor()->isStable()){
    this->_location = this->_home;
    return true;
  }
  return false;
}

bool Federation::Ship::move(Destination d) {
  if (d != this->_location && this->_core->checkReactor()->isStable()){
    this->_location = d;
    return true;
  }
  return false;
}

bool Federation::Ship::move() {
  if (this->_core->checkReactor()->isStable()){
    this->_location = this->_home;
    return true;
  }
  return false;
}

WarpSystem::Core *Federation::Ship::getCore() {
  return this->_core;
}

Federation::Starfleet::Captain::Captain(std::string name) {
  this->_name = name;
  this->_age = 0;
}

Federation::Starfleet::Captain::~Captain() {

}

std::string Federation::Starfleet::Captain::getName() {
  return this->_name;
}

int Federation::Starfleet::Captain::getAge() {
  return this->_age;
}

void Federation::Starfleet::Captain::setAge(int age) {
  this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name) {
  this->_name = name;
  std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign() {

}
