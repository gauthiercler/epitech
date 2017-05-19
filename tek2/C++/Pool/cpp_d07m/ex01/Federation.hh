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

    class Captain{
    private:
      std::string 	_name;
      int		_age;

    public:
      Captain(std::string name);
      ~Captain();
      std::string getName();
      int	getAge();
      void	setAge(int age);
    };

    class Ship{

    private:
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*_core;
      Captain		*_captain;

    public:
      Ship(int length, int width, std::string name, short maxWarp);
      ~Ship();
      void	setupCore(WarpSystem::Core *core);
      void	checkCore();
      void	promote(Captain *captain);

    };

    class Ensign{
    private:
      std::string _name;

    public:
      explicit Ensign(std::string name);
      ~Ensign();
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
