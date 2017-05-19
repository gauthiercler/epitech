/*
** Borg.hpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07m/ex01/Borg.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 11:20:37 2017 Gauthier CLER
** Last update Tue Jan 10 11:20:37 2017 Gauthier CLER
*/

#ifndef CPP_D07M_BORG_H
#define CPP_D07M_BORG_H


#include "WarpSystem.hh"
#include "Destination.hh"

namespace Borg {
  class	Ship{
  private:
    int			_side;
    short		_maxWarp;
    WarpSystem::Core	*_core;
    Destination		_location;
    Destination 	_home;

  public:
    Ship();
    ~Ship();
    void	setupCore(WarpSystem::Core *core);
    void	checkCore();
    bool	move(int warp, Destination d);
    bool	move(int warp);
    bool	move(Destination d);
    bool	move();
  };
}


#endif //CPP_D07M_BORG_H
