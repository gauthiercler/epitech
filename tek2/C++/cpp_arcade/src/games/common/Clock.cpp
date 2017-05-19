/*
** Clock.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/games/common/Clock.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Apr 07 00:39:37 2017 Gauthier Cler
** Last update Fri Apr 07 00:39:39 2017 Gauthier Cler
*/

#include <chrono>
#include "Clock.hpp"

Clock::Clock(uint64_t ticks) : _clock(std::chrono::system_clock::now()), _ticks(ticks){

}

bool Clock::tick() {
  std::chrono::time_point<std::chrono::system_clock>	currentTime = std::chrono::system_clock::now();
  if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - this->_clock).count() >
      static_cast<int64_t>(this->_ticks)){
    this->_clock = std::chrono::system_clock::now();
    return true;
  }
  return false;
}

Clock::~Clock() {

}
