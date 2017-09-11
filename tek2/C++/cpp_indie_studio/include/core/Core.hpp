/*
** Core.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Core.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:48:44 2017 Anthony LECLERC
** Last update jeu. mai 04 15:48:44 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_CORE_HPP
#define CPP_INDIE_STUDIO_CORE_HPP

#include <maps/MapFileManager.hpp>
#include "IrrlichtWrapper.hpp"
#include "menu/Menu.hpp"
#include "menu/SplashScreen.hpp"
#include "game/Game.hpp"


namespace indie {

  /**
   * @brief Core
   */
  class ICoreController;
  class ICoreState;
  class MenuCoreState;
  class GameCoreState;
  class PauseCoreState;

  class Core {
  public:
    static MenuCoreState *MenuState;
    static GameCoreState *GameState;
    static PauseCoreState *PauseState;
  private:
    IrrlichtWrapper	&_wrapper;
    ICoreController	*_controller;
    ICoreState		*_state;

    MapFileManager      _filesManager;
    SplashScreen	_splashScreen;

    MapAttributes				_map;
    std::vector<indie::Game::PlayerInfo>	_playersInfo;
    bool					_mapLoaded;

  public:
    Core();
    ~Core();


    MapAttributes const& getMap() const;
    std::vector<indie::Game::PlayerInfo> const &getPlayersInfo(void) const;
    std::vector<std::pair<irr::io::path, MapAttributes> > const& getMaps() const;
    bool		clear();
    void		run();
    void		close(void);
    void		changeToGame(MapAttributes const &map, const std::vector<indie::Game::PlayerInfo> &playerInfos);
    void		changeToGame(const std::vector<indie::Game::PlayerInfo> &playerInfos);
    void		changeToMenu();
    void		changeToPause();
    void		changeState(ICoreState *state);
    bool		isMapLoaded(void) const;

  };
}


#endif //CPP_INDIE_STUDIO_CORE_HPP