/*
** Pacman.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/games/snake/includes/Pacman.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed Apr 05 08:57:23 2017 Vincent DUSAUTOIR
** Last update Wed Apr 05 08:57:23 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_PACMAN_HPP
#define CPP_ARCADE_PACMAN_HPP

#include <vector>
#include <Clock.hpp>
#include <Scores.hpp>
#include <Input.hpp>
#include "IGame.hpp"
#include "Protocol.hpp"
#include "Ghost.hpp"
#include "DFS.hpp"

namespace arcade
{

  class Pacman : public IGame
  {



    enum direction
    {
      UP,
      DOWN,
      LEFT,
      RIGHT
    };

    IGraphic				*_glib;
    direction				_direction;
    IFrame				*_frame;
    IFrame				*_banner;
    ISprite				*_sprite;
    IPicture				*_wall;
    unsigned int			_total;
    std::pair<int, int>			_playerPosition;
    std::vector<std::vector<cellType>>	_map;
    std::vector<std::vector<bool>>	_cachedMap;
    std::vector<Ghost>			_ennemies;
    Clock				_clock;
    std::chrono::time_point<std::chrono::system_clock> _startedGameTime;
    Scores				_score;
    bool				_scoreEntered;
    Input				_input;
    bool				_canEatEnemies;
    uint64_t				_move;
    std::chrono::time_point<std::chrono::system_clock> _canEatEnemiesTime;
    long						_timeElapsed;

  public:
    Pacman();
    virtual		~Pacman();
    virtual void	Play();
    virtual void	init(IGraphic &glib);
    virtual void	close();
    virtual void	reload(IGraphic &glib);
    virtual void	receiveEvent(const IEvent &event);
    virtual void	dumpMap() const;
    void		movePlayer();
    IGraphic		*getGraphic() const;
    void		setGraphic(IGraphic *glib);
    void		setDirection(direction dir);
    direction		getDirection();
    void		update();
    void		eat();
    void		cleanMap();
    void		drawPacman();
    void		addNewGhost();
    void		display();
    bool		isDead();
    void		displayDead();
    void		registerScore();
    const std::vector<std::vector<TileType>>	&getMap() const;
    const std::pair<int, int>			&getHead() const;
    int			mapSize = 21;
    int			cellSize = 40;
  };
}

#endif //CPP_ARCADE_PACMAN_HPP
