/*
** BorgQueen.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07m/ex04/BorgQueen.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 14:38:48 2017 Gauthier CLER
** Last update Tue Jan 10 14:38:49 2017 Gauthier CLER
*/

#include "BorgQueen.hh"
#include "Borg.hh"

Borg::BorgQueen::BorgQueen() {
  this->firePtr = &Borg::Ship::fire;
  this->movePtr = &Borg::Ship::move;
  this->destroyPtr = &Borg::Ship::fire;
}

Borg::BorgQueen::~BorgQueen() {

}

void Borg::BorgQueen::fire(Borg::Ship *borg, Federation::Starfleet::Ship *ship) {
  (borg->*(this->firePtr))(ship);
}

bool Borg::BorgQueen::move(Borg::Ship *borg, Destination d) {
  return (borg->*(this->movePtr))(d);
}

void Borg::BorgQueen::destroy(Borg::Ship *borg, Federation::Ship *ship) {
  (borg->*(this->destroyPtr))(ship);
}
