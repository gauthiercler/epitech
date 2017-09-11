/*
** Menu.hpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/include/menu/Menu.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed May 24 10:47:36 2017 Vincent DUSAUTOIR
** Last update Wed May 24 10:47:36 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_INDIE_STUDIO_MENU_HPP
#define CPP_INDIE_STUDIO_MENU_HPP

namespace indie{
  class Core;
}

#include <map>
#include <maps/MapInfo.hpp>
#include "game/Position.hpp"
#include "core/IController.hpp"
#include "IrrlichtWrapper.hpp"
#include "IMenu.hpp"

namespace indie
{

  class IMenuController;

  class Menu : public IController {

  public:

    MapAttributes map;

    Menu(Core &core);
    virtual ~Menu();

    enum MenuType
    {
      MAIN = 0,
      OPTIONS,
      PLAYER_SELECT,
      MAP_SELECT,
      HIGHSCORES
    };

    virtual void	receiveEvent(const indie::EventManager &eventManager);
    virtual bool	update();
    virtual bool	clear();
    virtual bool	render();
    void		changeCurrentMenu(MenuType menu);
    void		changeToGame(const MapAttributes &map) const;
    void		changeToGame(void) const;
    void		close(void) const;
    bool		hasSave(void) const;
    std::vector<std::pair<irr::io::path, MapAttributes>> const &getMaps(void) const;

    virtual void setActive(bool b) override;

  private:

    Core							&_core;
    std::vector<std::unique_ptr<IMenu>>				_menus;
    MenuType 							_currentMenu;
    bool							_hasSave;
  };
}

#endif //CPP_INDIE_STUDIO_MENU_HPP
