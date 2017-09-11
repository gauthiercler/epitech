/*
** OptionsMenu.h for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/include/menu/OptionsMenu.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri May 26 15:56:13 2017 Anas Buyumad
** Last update Fri Jun 16 17:18:48 2017 Sylvain Chaugny
*/

#ifndef CPP_INDIE_STUDIO_OPTIONSMENU_H
#define CPP_INDIE_STUDIO_OPTIONSMENU_H

#include <functional>
#include "IMenu.hpp"
#include "Menu.hpp"
#include "MenuButton.hpp"

namespace indie
{
  class OptionsMenu : public IMenu
  {

  public:

    enum AILevel
    {
      EASY = 0,
      MEDIUM,
      HARD
    };

  private:

    struct function
    {
      std::function<void (irr::EKEY_CODE)>	first;
      std::function<void (irr::EKEY_CODE)>	second;
    };

    indie::Menu				&_menu;
    std::vector<std::pair<std::pair<irr::EKEY_CODE, indie::keyStates>, std::function<void (void)>>>								_events;
    std::vector<std::pair<std::unique_ptr<MenuButton>, function>>			_buttons;
    std::vector<std::pair<std::unique_ptr<MenuButton>, function>>::iterator		_currentButton;
    std::vector<std::unique_ptr<MenuButton>>															_configButtons;
    std::map<AILevel, std::string>	_AIDifficulties;
    AILevel				_AILevel;
    std::vector<Game::PlayerInfo> playerConfig;

  public:

    OptionsMenu(indie::Menu &menu);
    ~OptionsMenu();

    virtual void	receiveEvent(const indie::EventManager &eventManager);
    virtual void	buildElements(void);
    virtual void	render(void);

    void		jumpNext(void);
    void		jumpPrev(void);
    void		moveLeft(void);
    void		moveRight(void);

    virtual const std::vector<Game::PlayerInfo> &getPlayerConfig();

    std::vector<std::unique_ptr<MenuButton>>::iterator		findConfigButton(const std::string &name);

    void		drawSelected(const std::string &selectedElement);
    void		changeSound(irr::EKEY_CODE key);
    void		changeAILevel(irr::EKEY_CODE key);
    void		changeToMainMenu(void) const;
  };
}

#endif //CPP_INDIE_STUDIO_OPTIONSMENU_H
