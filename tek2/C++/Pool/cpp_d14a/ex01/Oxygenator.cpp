/*
** Oxygenator.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14a/ex01/Oxygenator.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 18:08:11 2017 Gauthier CLER
** Last update Tue Jan 17 18:08:11 2017 Gauthier CLER
*/

#include <iostream>
#include "Errors.hpp"
#include "Oxygenator.hpp"

Oxygenator::Oxygenator()
    : _quantity(0)
{
}

void
Oxygenator::generateOxygen()
{
    _quantity += 10;
}

void
Oxygenator::useOxygen(int quantity)
{
  if (_quantity - quantity < 10)
    throw LifeCriticalError("Not enough oxygen to live.", "Oxygenator");
  _quantity -= quantity;
  if (_quantity <= 10)
    throw MissionCriticalError("Not enough oxygen to continue the mission.", "Oxygenator");
}
