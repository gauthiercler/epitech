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


#include "Destination.hh"
#include "Federation.hh"

namespace Borg {
  class	Ship{
  private:
    int			_side;
    short		_maxWarp;
    WarpSystem::Core	*_core;
    Destination		_location;
    Destination 	_home;
    int			_shield;
    int			_weaponFrequency;
    short		_repair;

  public:
    Ship(int weaponFrequency, short repair = 3);
    ~Ship();
    void	setupCore(WarpSystem::Core *core);
    void	checkCore();
    bool	move(int warp, Destination d);
    bool	move(int warp);
    bool	move(Destination d);
    bool	move();
    int		getShield();
    void	setShield(int shield);
    int		getWeaponFrequency();
    void	setWeaponFrequency(int frequency);
    short	getRepair();
    void	setRepair(short repair);
    void	fire(Federation::Starfleet::Ship *ship);
    void	fire(Federation::Ship *ship);
    void	repair();
  };
}


#endif //CPP_D07M_BORG_H
