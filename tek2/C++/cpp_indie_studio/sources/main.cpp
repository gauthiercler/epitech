/*
** main.cpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/sources/main.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri May 05 11:43:43 2017 Vincent DUSAUTOIR
** Last update Fri May 05 11:43:43 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include <core/Random.hpp>
#include <maps/IJsonLoader.hpp>
#include <maps/MapLoader.hpp>
#include <maps/Errors.hpp>
#include <game/Highscore.hpp>
#include "core/Core.hpp"
#include "maps/MapFileManager.hpp"

int main(void)
{
  indie::Core core;

  core.run();
  return 0;
}