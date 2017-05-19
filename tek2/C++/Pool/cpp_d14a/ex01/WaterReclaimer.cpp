/*
** WaterReclaimer.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14a/ex01/WaterReclaimer.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 18:08:23 2017 Gauthier CLER
** Last update Tue Jan 17 18:08:23 2017 Gauthier CLER
*/

#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer()
    : _water(0),
      _started(false)
{
}

void
WaterReclaimer::start()
{
  if (_water <= 0)
    throw MissionCriticalError("Not enough water to achieve the mission.", "WaterReclaimer");
  _started = true;
}

void
WaterReclaimer::useWater(int water)
{
  if (!_started)
    throw UserError("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer");
  if (water < 0)
    throw UserError("Water use should be positif.", "WaterReclaimer");
  else if (_water - water < 10)
    throw LifeCriticalError("Cannot use water, not enough in the reclaimer.", "WaterReclaimer");
  _water -= water;
}

void
WaterReclaimer::generateWater()
{
  if (_water + 10 > 100)
    throw NasaError("Cannot generate water, reclaimer already full.", "WaterReclaimer");
  _water += 10;
}
