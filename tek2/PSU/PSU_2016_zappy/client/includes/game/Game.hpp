/*
** Game.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/game/Game.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 13:57:22 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 13:57:24 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_GAME_HPP
#define PSU_2016_ZAPPY_GAME_HPP

#include "server/Parser.hpp"
#include "managers/EventManager.hpp"
#include "Map.hpp"

namespace zappy{
  class			Core;


  class			Game{
    Core		&_core;
    Map			_map;
    Position		_mousePos;
    bool		_mousePress;
    Tiles		*_tile;
    std::chrono::time_point<std::chrono::system_clock> _last;
    size_t		_currentPlayer;
    size_t		_serverTick;
    size_t		_tick;
    bool		_help;
    std::vector<std::shared_ptr<Player>> _players;
    std::vector<std::pair<std::pair<sf::Event::EventType, sf::Keyboard::Key>, std::function<void(void)>>>	_keyboardEvents;
    std::vector<std::pair<sf::Event::EventType, std::function<void(EventManager &)>>>	_mouseEvents;
    std::vector<std::pair<ParseType, std::function<void(const Parser &)>>>	_serverResponses;

  public:
    Game(Core &core);
    ~Game();

    void		render();
    void		buttonPressed(EventManager &event);
    void		buttonReleased(EventManager &event);
    void		mouseMoving(EventManager &event);
    void		handleTile();
    void		removeTile();
    void		handlePlayers();
    void		removePlayers();
    void		addPlayer();
    void		removePlayer();
    void		disconnect();
    void		update(EventManager &event);
    void		update(const Parser &parser);
    void		initMap(const Parser &parser);
    void		responseTick(const Parser &parser);
    void		update();
    void		addTick();
    void		removeTick();
    void		sendTick();
    void		goHelp();
    void		stopHelp();

  protected:
    void		renderTick();
    void		renderHelp();
    void		renderH();
  };
}

#endif //PSU_2016_ZAPPY_GAME_HPP
