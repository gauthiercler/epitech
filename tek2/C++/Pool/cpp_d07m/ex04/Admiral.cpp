/*
** Admiral.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07m/ex04/Admiral.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 14:39:11 2017 Gauthier CLER
** Last update Tue Jan 10 14:39:11 2017 Gauthier CLER
*/

#include <iostream>
#include "Admiral.hh"

Federation::Starfleet::Admiral::Admiral(std::string name) {
  this->_name = name;
  std::cout << "Admiral " << this->_name << " ready for action." << std::endl;
  this->movePtr = &Federation::Starfleet::Ship::move;
  this->firePtr = &Federation::Starfleet::Ship::fire;
}

Federation::Starfleet::Admiral::~Admiral() {

}

void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship,
					  Borg::Ship *borg) {
  std::cout << "On order from Admiral " << this->_name << ":" << std::endl;
  (ship->*(this->firePtr))(borg);
}

bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *ship,
					  Destination d) {
  return (ship->*(this->movePtr))(d);
}
