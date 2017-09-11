/*
** IMenu.h for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/include/menu/IMenu.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri May 26 15:42:56 2017 Anas Buyumad
** Last update Fri May 26 15:42:56 2017 Anas Buyumad
*/

#ifndef CPP_INDIE_STUDIO_IMENU_H
#define CPP_INDIE_STUDIO_IMENU_H

#include "managers/EventManager.hpp"
#include "game/Game.hpp"

namespace indie
{

  class IMenu
  {
  public:

    virtual void	receiveEvent(const indie::EventManager &eventManager) = 0;
    virtual void	buildElements(void) = 0;
    virtual void	render(void) = 0;
    virtual const std::vector<indie::Game::PlayerInfo> &getPlayerConfig() = 0;
  };
}

#endif //CPP_INDIE_STUDIO_IMENU_H
