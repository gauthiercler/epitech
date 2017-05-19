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

namespace Borg {
  class	Ship{
  private:
    int			_side;
    short		_maxWarp;
    WarpSystem::Core	*_core;

  public:
    Ship();
    ~Ship();
    void	setupCore(WarpSystem::Core *core);
    void	checkCore();

  };
}


#endif //CPP_D07M_BORG_H
