/*
** HomeMenu.h for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/include/menu/HomeMenu.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri May 26 15:56:16 2017 Anas Buyumad
** Last update Fri Jun 16 17:18:27 2017 Sylvain Chaugny
*/

#ifndef CPP_INDIE_STUDIO_HOMEMENU_H
#define CPP_INDIE_STUDIO_HOMEMENU_H

#include <functional>
#include <game/Game.hpp>
#include "IMenu.hpp"
#include "Menu.hpp"
#include "MenuButton.hpp"

namespace indie
{
  class HomeMenu : public IMenu
  {
  private:

    indie::Menu		&_menu;
    std::vector<std::pair<std::pair<irr::EKEY_CODE, indie::keyStates>, std::function<void (void)>>>	_events;
    std::vector<std::pair<std::unique_ptr<MenuButton>, std::function<void (void)>>>			_buttons;
    std::vector<std::pair<std::unique_ptr<MenuButton>, std::function<void (void)>>>::iterator		_currentButton;
    std::vector<indie::Game::PlayerInfo>	playerInfo;

  public :

    HomeMenu(indie::Menu &menu);
    ~HomeMenu();

    virtual void	receiveEvent(const indie::EventManager &eventManager);
    virtual void	buildElements(void);
    virtual void	render(void);

    std::vector<std::pair<std::unique_ptr<MenuButton>, std::function<void (void)>>>::iterator findButton(const std::string &name);
    void		jumpNext(void);
    void		jumpPrev(void);
    void		select(void);

    void		drawSelected(const std::string &selectedElement);
    void		resumeGame(void) const;
    void		changeToPlayerSelect(void) const;
    void		changeToOptions(void) const;
    void		changeToHighscores(void) const;
    virtual const std::vector<indie::Game::PlayerInfo> &getPlayerConfig();
  };
}

#endif //CPP_INDIE_STUDIO_HOMEMENU_H
