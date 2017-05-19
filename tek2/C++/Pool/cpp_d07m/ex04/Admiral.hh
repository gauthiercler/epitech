/*
** Admiral.h for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07m/ex04/Admiral.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 14:39:04 2017 Gauthier CLER
** Last update Tue Jan 10 14:39:04 2017 Gauthier CLER
*/


#ifndef CPP_D07M_ADMIRAL_H
#define CPP_D07M_ADMIRAL_H

#include <string>
#include "Federation.hh"

namespace Federation{
  namespace Starfleet{
    class Admiral {

    private:
      std::string	_name;
    public:
      Admiral(std::string name);
      ~Admiral();
      bool (Federation::Starfleet::Ship::*movePtr)(Destination d);
      void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship* ship);
      void fire(Federation::Starfleet::Ship*, Borg::Ship*);
      bool move(Federation::Starfleet::Ship*, Destination);
    };
  }
}



#endif //CPP_D07M_ADMIRAL_H
