/*
** MenuController.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MenuController.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 08 19:00:19 2017 Anthony LECLERC
** Last update jeu. juin 08 19:00:19 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_MENUCONTROLLER_HPP
# define CPP_INDIE_STUDIO_MENUCONTROLLER_HPP

#include "menu/Menu.hpp"
#include "controllers/EntityController.hpp"

namespace indie
{
  class IMenuController : public IEventController {
  protected:
    Menu& _menu;
    std::map<std::pair<irr::EKEY_CODE, indie::keyStates>, std::function<void (void)>>	_events;

  public:
    IMenuController(Menu& menu);

    void execute(EventManager const& events);
  };

  /**
   * @brief Controller events for active menu.
   * Should be active when the menu GUI is active.
   * set inactive when the core switches to the game.
   */
  class IMenuActiveController : public IMenuController {
  public:
    IMenuActiveController(Menu& menu);
  };

  /**
   * @brief Controller events for inactive menu
   * Basically do nothing, maybe not later...
   */
  class IMenuInGameController : public IMenuController {
  public:
    IMenuInGameController(Menu& menu);
  };
};

#endif //CPP_INDIE_STUDIO_MENUCONTROLLER_HPP
