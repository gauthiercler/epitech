/*
** Snake.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/games/snake/includes/Snake.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed Apr 05 08:57:23 2017 Vincent DUSAUTOIR
** Last update Wed Apr 05 08:57:23 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_SNAKE_HPP
#define CPP_ARCADE_SNAKE_HPP

#include <vector>
#include "Clock.hpp"
#include "Scores.hpp"
#include "Input.hpp"
#include "IGame.hpp"
#include "Protocol.hpp"

namespace arcade
{
  class Snake : public IGame
  {
    enum direction
    {
      UP,
      DOWN,
      LEFT,
      RIGHT
    };

    IGraphic				*_glib;
    IFrame				*_frame;
    IFrame				*_banner;
    direction				_direction;
    unsigned int			_total;
    Clock				_clock;
    bool				_scoreEntered;
    Input				_input;
    Scores				_score;
    std::pair<int, int>			_head;
    std::vector<std::pair<int, int>>	_tail;
    std::vector<std::vector<TileType>>	_map;
    std::pair<int, int>			_fruits;

  public:
    Snake();
    virtual		~Snake();
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
    void		registerScore();
    void		update();
    void		cleanMap();
    void		display();
    void		displayDead();
    bool		isDead();
    void		eat();
    const std::vector<std::vector<TileType>>	&getMap() const;
    const std::pair<int, int>			&getHead() const;
    const std::vector<std::pair<int, int>>	&getTail() const;
    int			mapSize = 21;
    int			cellSize = 40;
  };
}

#endif //CPP_ARCADE_SNAKE_HPP
