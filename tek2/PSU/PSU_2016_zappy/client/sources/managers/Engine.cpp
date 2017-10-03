/*
** SfmlManager.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/managers/SfmlManager.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 11:30:41 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 11:30:41 2017 Vincent DUSAUTOIR
*/

#include "managers/Engine.hpp"

std::unique_ptr<zappy::Wrapper> zappy::Engine::_sfmlWrapper(nullptr);

zappy::Wrapper &zappy::Engine::get() {
  if (_sfmlWrapper == nullptr)
    _sfmlWrapper = std::make_unique<Wrapper>();
  return (*_sfmlWrapper);
}

