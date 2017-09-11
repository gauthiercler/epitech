/*
** MapSelectMenu.h for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/include/menu/MapSelectMenu.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jun 17 22:42:44 2017 Anas Buyumad
** Last update Sat Jun 17 22:42:44 2017 Anas Buyumad
*/

#ifndef CPP_INDIE_STUDIO_MAPSELECTMENU_H
#define CPP_INDIE_STUDIO_MAPSELECTMENU_H

#include "IMenu.hpp"
#include "Menu.hpp"

namespace indie
{
  class MapSelectMenu : public IMenu
  {

    class MapConfig
    {

    public:

      enum MapType
      {
	RANDOM = 0,
	LOADED
      };

      MapConfig(irr::video::ITexture *info, irr::video::ITexture *display, MapType type, const std::vector<std::pair<irr::io::path, MapAttributes>>::const_iterator map);
      ~MapConfig();

      void	drawElements(void) const;
      MapType	getType(void) const;
      const std::vector<std::pair<irr::io::path, MapAttributes>>::const_iterator	getMap(void) const;

    private:

      irr::video::ITexture	*_info;
      irr::video::ITexture	*_display;
      MapType 			_type;
      const std::vector<std::pair<irr::io::path, MapAttributes>>::const_iterator _map;

    };

  private:

    indie::Menu		&_menu;
    std::vector<std::pair<irr::io::path, MapAttributes>> const &_maps;
    std::vector<std::pair<std::pair<irr::EKEY_CODE, indie::keyStates>, std::function<void (void)>>>	_events;

    std::vector<std::unique_ptr<MapConfig>>					_mapConfigs;
    std::vector<std::unique_ptr<MapConfig>>::iterator				_currentMap;
    std::vector<Game::PlayerInfo> playerInfo;
  public:
    virtual const std::vector<Game::PlayerInfo> &getPlayerConfig();

  public:

    MapSelectMenu(indie::Menu &menu);
    ~MapSelectMenu();

    virtual void		receiveEvent(const indie::EventManager &eventManager);
    virtual void		buildElements(void);
    virtual void		render(void);

    void			changeToPlayerSelect(void) const;
    void			changeToGame(void) const;
    void			jumpPrev(void);
    void			jumpNext(void);
  };
}

#endif //CPP_INDIE_STUDIO_MAPSELECTMENU_H