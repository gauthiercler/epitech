/*
** Engine.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14a/ex01/Engine.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 18:08:03 2017 Gauthier CLER
** Last update Tue Jan 17 18:08:03 2017 Gauthier CLER
*/

#include <cmath>
#include <sstream>
#include "Errors.hpp"
#include "Engine.hpp"

#define POW_2(x) (x * x)
#define ABS(x) (x < 0 ? -x : x)

Engine::Engine(float power, float x, float y)
    : _power(power),
      _x(x),
      _y(y)
{

}

Engine::~Engine()
{

}

void
Engine::goTorward(float x, float y)
{
  if (this->distanceTo(x, y) > this->_power){
    std::ostringstream error;
    error << "Cannot reach destination (" << x << ", " << y << ").";
    throw UserError(error.str(), "Engine");
  }
  _x = x;
  _y = y;
}

float
Engine::distanceTo(float x, float y) const
{
    return std::sqrt(POW_2(ABS(x - _x)) + POW_2(ABS(y - _y)));
}

float
Engine::getX() const
{
    return _x;
}

float
Engine::getY() const
{
    return _y;
}

