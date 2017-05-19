/*
** BorgQueen.h for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07m/ex04/BorgQueen.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 14:38:27 2017 Gauthier CLER
** Last update Tue Jan 10 14:38:27 2017 Gauthier CLER
*/

#ifndef CPP_D07M_BORGQUEEN_H
#define CPP_D07M_BORGQUEEN_H


#include "Federation.hh"

namespace Borg{
  class BorgQueen {

  public:
    BorgQueen();
    ~BorgQueen();
    bool (Borg::Ship::*movePtr)(Destination d);
    void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship* ship);
    void (Borg::Ship::*destroyPtr)(Federation::Ship *ship);
    void fire(Borg::Ship *borg, Federation::Starfleet::Ship *ship);
    void destroy(Borg::Ship *borg, Federation::Ship *ship);
    bool move(Borg::Ship *borg, Destination);
  };
}


#endif //CPP_D07M_BORGQUEEN_H
