/*
** MenuController.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MenuController.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juin 11 01:29:18 2017 Anthony LECLERC
** Last update Fri Jun 16 17:19:52 2017 Sylvain Chaugny
*/

#include <functional>
#include <iostream>
#include "controllers/MenuController.hpp"

void indie::IMenuController::execute(EventManager const &events)
{
  for (auto event : this->_events)
  {
    switch (event.first.second)
    {
      case PRESSED:
	if (events.isKeyPressed(event.first.first))
	  event.second();
	break;
      case DOWN:
	if (events.isKeyDown(event.first.first))
	  event.second();
	break;
      case UP:
	if (events.isKeyUp(event.first.first))
	  event.second();
	break;
      case RELEASED:
	if (events.isKeyReleased(event.first.first))
	  event.second();
	break;
    }
  }
}

indie::IMenuController::IMenuController(indie::Menu &menu) :
    _menu(menu)
{}

indie::IMenuActiveController::IMenuActiveController(indie::Menu &menu)  : IMenuController(menu)
{
}

indie::IMenuInGameController::IMenuInGameController(indie::Menu &menu) :
    IMenuController(menu)
{}
