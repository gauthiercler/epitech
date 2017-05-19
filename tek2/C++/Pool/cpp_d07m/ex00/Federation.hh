/*
** Federation.h for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07m/ex00/Federation.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 10:20:01 2017 Gauthier CLER
** Last update Tue Jan 10 10:20:01 2017 Gauthier CLER
*/


#ifndef CPP_D07M_FEDERATION_H
#define CPP_D07M_FEDERATION_H


#include <string>
#include "WarpSystem.hh"

namespace Federation{

  namespace Starfleet{

    class Ship{

    private:
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*core;

    public:
      Ship(int length, int width, std::string name, short maxWarp);
      ~Ship();
      void	setupCore(WarpSystem::Core *core);
      void	checkCore();

    };
  }
  class Ship{

  private:
    int		_length;
    int		_width;
    std::string	_name;
    short		_maxWarp;
    WarpSystem::Core	*core;

  public:
    Ship(int length, int width, std::string name);
    ~Ship();
    void	setupCore(WarpSystem::Core *core);
    void	checkCore();

  };
}


#endif //CPP_D07M_FEDERATION_H
