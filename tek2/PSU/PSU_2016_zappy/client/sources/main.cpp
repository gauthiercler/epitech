/*
** main.cpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/client/main.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jun 20 10:30:45 2017 Gauthier Cler
** Last update Tue Jun 20 10:30:45 2017 Gauthier Cler
*/

#include <Core.hpp>
#include <iostream>
#include <managers/Engine.hpp>
#include "utils/Error.hpp"

int		main(void)
{
  try {
    zappy::Engine::get();
    zappy::Core	core;
    core.run();
  } catch (std::exception &e) {
    std::cerr << "Error on : " << std::endl << e.what() << std::endl;
  }
  return 0;
}