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

Federation::Starfleet::Ship::Ship(int length, int width, std::string name,
				  short maxWarp) {
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;
  this->_core = NULL;
  std::cout << "The ship USS " << this->_name << " has been finished. It is "
	    << this->_length << " m in length and " << this->_width << " m in width."
	    << std::endl;
  std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
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

Federation::Ship::Ship(int length, int width, std::string name) {
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = 1;
  this->core = NULL;
  std::cout << "The independant ship " << this->_name << " just finished its construction. It is "
	    << this->_length << " m in length and " << this->_width << " m in width."
	    << std::endl;
}

Federation::Ship::~Ship() {

}

void Federation::Ship::setupCore(WarpSystem::Core *core) {
  this->core = core;
  std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore() {
  std::cout << this->_name << ": The core is "
	    << ((this->core->checkReactor()->isStable()) ? "stable" : "unstable")
	    << " at the time." << std::endl;
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
