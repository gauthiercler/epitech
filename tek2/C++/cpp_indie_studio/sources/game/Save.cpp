/*
** Save.cpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/sources/game/Save.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Jun 12 15:40:03 2017 Vincent DUSAUTOIR
** Last update Mon Jun 12 15:40:03 2017 Vincent DUSAUTOIR
*/

#include <fstream>
#include "game/Save.hpp"

indie::Save::Save() {

}

indie::Save::~Save() {

}

bool indie::Save::isAvailable() {
  std::ifstream file(this->_name.c_str());
  return static_cast<bool>(file);
}

void indie::Save::load() {

}
