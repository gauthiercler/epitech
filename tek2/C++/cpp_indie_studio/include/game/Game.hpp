/*
** Game.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Game.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:24:56 2017 Anthony LECLERC
** Last update Fri Jun 16 17:16:14 2017 Sylvain Chaugny
*/

#ifndef CPP_INDIE_STUDIO_GAME_HPP
#define CPP_INDIE_STUDIO_GAME_HPP

namespace indie{
  class Core;
}

#include <functional>
#include <map>
#include <entity/Camera.hpp>
#include "core/IController.hpp"
#include "IrrlichtWrapper.hpp"
#include "entity/HumanPlayer.hpp"
#include "Map.hpp"
#include "MapManager.hpp"
#include "CollisionManager.hpp"
#include "IA.hpp"
#include "controllers/PlayerController.hpp"

namespace indie {

  /**
   * @brief Game
   */
  class Game : public IController {

    class Hud
    {
    private:

      enum InfoDelta
      {
	PowerDelta = 110,
	BombsDelta = 140,
	SpeedDelta = 170,
	ScoreDelta = 200
      };

      struct ScoreInfo
      {
	irr::gui::IGUIStaticText	*power;
	irr::gui::IGUIStaticText	*bombs;
	irr::gui::IGUIStaticText	*speed;
	irr::gui::IGUIStaticText	*score;
      };

      const Game			&_game;
      irr::gui::IGUIStaticText		*_fpsCounter;
      irr::gui::IGUIStaticText		*_timeCounter;
      std::vector<irr::core::vector2d<irr::s32>>	_positions;
      std::vector<ScoreInfo>		_scoreBoxes;
      bool 				_active;
      irr::u32				_startTime;

    public:

      Hud(const Game &game);
      ~Hud();

      void		build(void);
      void		render(void);
      bool		isActive() const;
      void		setActive(bool);
      void		setStartTime(irr::u32 startTime);
    };

  private:
    irr::scene::ISceneManager 	*smgr;
    Core		&_core;
    Hud			_hud;
    std::shared_ptr<Map> _map;
    Camera              _camera;
    MapManager		_mapManager;
    CollisionManager	_collMgr;
    std::vector<std::shared_ptr<APlayer>> _players;
    std::map<std::pair<irr::EKEY_CODE, indie::keyStates>, std::function<void (void)>>	_events;

    std::vector<IEventController *> _controllers;

    bool				_loading;
    bool				_tempo;
    bool				_over;
    irr::u32				_beginTime;
    bool				_beginTimeSet;
    irr::gui::IGUIImage			*_loadingScreen;
    std::map<std::string, std::pair<std::string, std::string>>	_playerNames;
    std::vector<std::unique_ptr<PlayerKeyboardController>>	_playerControllers;

    MapSaveInfos _save;


  public:

    enum PlayerMode
    {
      AI,
      HUMAN
    };

    struct PlayerInfo
    {
      std::string 		textureName;
      PlayerMode			type;
    };

    Game(Core &core, MapAttributes const& map, const std::vector<PlayerInfo> &players);
    Game(Core &core, const std::vector<PlayerInfo> &players);
    virtual ~Game();

    virtual void				receiveEvent(const indie::EventManager &eventManager);
    virtual bool				render();
    virtual bool				clear();
    virtual bool				update();
    void                			setActive(bool);
    bool					isEnded();
    std::shared_ptr<APlayer>			getBetterPlayer();

    const std::vector<std::shared_ptr<APlayer>>	&getPlayers() const;
    const std::map<std::string, std::pair<std::string, std::string>>	&getPlayerNames() const;
    MapSaveInfos& save();

    void		displayWinner(std::shared_ptr<APlayer> &winner);
    void		displayDraw(void);

  private:
    void		saveScores();
    void		generatePlayers(const std::vector<PlayerInfo> &players);
  };
}


#endif //CPP_INDIE_STUDIO_GAME_HPP
