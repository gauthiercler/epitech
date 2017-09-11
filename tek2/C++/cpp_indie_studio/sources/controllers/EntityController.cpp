/*
** EntityController.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/EntityController.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 08 22:13:41 2017 Anthony LECLERC
** Last update jeu. juin 08 22:13:41 2017 Anthony LECLERC
*/

#include "Engine.hpp"
#include "controllers/EntityController.hpp"

void indie::IEventController::setActive(bool state)
{
  _state = state;
}

bool indie::IEventController::isActive() const
{
  return _state;
}

indie::IEventController::IEventController() : _state(false)
{}

indie::IEventController::~IEventController() {
  Engine::get().getEventManager().remove(this);
}

indie::IEntityController::~IEntityController()
{}

indie::IEntityController::IEntityController() : IEventController()
{}