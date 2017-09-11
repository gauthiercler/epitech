/*
** HighscoreMenu.h for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/include/menu/HighscoreMenu.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jun 16 00:58:12 2017 Anas Buyumad
** Last update Fri Jun 16 17:20:57 2017 Sylvain Chaugny
*/

#ifndef CPP_INDIE_STUDIO_HIGHSCOREMENU_H
#define CPP_INDIE_STUDIO_HIGHSCOREMENU_H

#include <functional>
#include "IMenu.hpp"
#include "game/Highscore.hpp"
#include "Menu.hpp"
#include "MenuButton.hpp"

namespace indie
{
  class HighscoreMenu : public IMenu
  {
  private:

    indie::Menu			&_menu;
    std::vector<std::pair<std::pair<irr::EKEY_CODE, indie::keyStates>, std::function<void (void)>>>	_events;
    Highscore			_highscores;
    std::vector<Game::PlayerInfo> playerConfig;
  public:
    virtual const std::vector<Game::PlayerInfo> &getPlayerConfig();

  public :

    HighscoreMenu(indie::Menu &menu);
    ~HighscoreMenu();

    virtual void	receiveEvent(const indie::EventManager &eventManager);
    virtual void	buildElements(void);
    virtual void	render(void);

    void		changeToMainMenu(void);
  };
}

#endif //CPP_INDIE_STUDIO_HIGHSCOREMENU_H
