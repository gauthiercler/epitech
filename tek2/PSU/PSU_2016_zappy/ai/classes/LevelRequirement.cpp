/*
** LevelRequirement.cpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/classes/LevelRequirement.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jun 28 17:40:42 2017 Gauthier Cler
** Last update Wed Jun 28 17:40:42 2017 Gauthier Cler
*/

#include "LevelRequirement.hpp"

ai::LevelRequirement	ai::LevelRequirement::singleton;

const ai::LevelRequirement &ai::LevelRequirement::get() {
  return singleton;
}

const std::pair<unsigned int, ai::Inventory>
ai::LevelRequirement::operator[](unsigned int index) const {
  return _list.at(index - 2);
}
