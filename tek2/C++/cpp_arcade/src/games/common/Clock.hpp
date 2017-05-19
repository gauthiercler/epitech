/*
** Clock.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/games/common/Clock.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Apr 07 00:37:53 2017 Gauthier Cler
** Last update Fri Apr 07 00:37:53 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_CLOCK_HPP
#define CPP_ARCADE_CLOCK_HPP


#include <stdint-gcc.h>
#include <chrono>

class Clock {
public:
  Clock(uint64_t ticks);
  bool	tick();
  ~Clock();

private:
  std::chrono::time_point<std::chrono::system_clock> 	_clock;
  uint64_t						_ticks;
};


#endif //CPP_ARCADE_CLOCK_HPP
