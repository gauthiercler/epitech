/*
** Map.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/game/Map.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 22 08:50:25 2017 Vincent DUSAUTOIR
** Last update Thu Jun 22 08:50:25 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_MAP_HPP
#define PSU_2016_ZAPPY_MAP_HPP

#include <map>
#include <memory>
#include <server/Parser.hpp>
#include "utils/Size.hpp"
#include "utils/Position.hpp"
#include "Tiles.hpp"
#include "Player.hpp"
#include "Egg.hpp"
#include "Chat.hpp"

namespace zappy {

  class			Map{
    Size							_size;
    Position							_offset;
    Size							_scale;
    std::vector<std::pair<Position, std::shared_ptr<Tiles>>>	_tiles;
    std::vector<std::shared_ptr<Player>>			_players;
    std::vector<std::shared_ptr<Egg>>				_eggs;
    Position							_mousePos;
    bool							_mousePress;
    bool							_generated;
    Chat							_chat;

  public:
    Map(const Size &size);
    Map();
    ~Map();

    void		update(const Position &pos, bool pressed = false);
    void		update();
    void		generate();
    void		render();
    Position		getPosition(const Position &pos);
    void		renderMouse();
    void		move(const Position &pos);
    void		moveLeft();
    void		moveRight();
    void		moveUp();
    void		moveDown();
    void		addScale();
    void		resetOffset();
    void		removeScale();
    void		openChat();
    void		setSize(const Size &size);
    Tiles		*getTileAtPos(const Position &pos, bool mousepos = true);
    bool		isInMap(const Position &pos);
    std::vector<std::shared_ptr<Player>> getPlayersAtPos(const Position &pos);
    void		reset();
    bool		isGenerated();

    // SERVER RESPONSES
    void		setTileContent(const Parser &parser);
    void		spawnPlayer(const Parser &parser);
    void		changePlayerPosition(const Parser &parser);
    void		changePlayerLevel(const Parser &parser);
    void		changePlayerInventory(const Parser &parser);
    void		excludePlayer(const Parser &parser);
    void		broadcastPlayer(const Parser &parser);
    void		spawnEgg(const Parser &parser);
    void		excludeEgg(const Parser &parser);
    void		spawnIncantation(const Parser &parser);
    void		endIncantation(const Parser &parser);
    void		serverMessage(const Parser &parser);

  protected:
    void		addPlayer(size_t id, const Position &pos, Orientation orientation, size_t level, const std::string &teamName);
    void		addEgg(size_t id, const Position &pos, const std::string &teamName);
    void		removePlayer(size_t id);
    void		removeEgg(size_t id);
    Player		*getPlayerById(size_t id);
    Egg			*getEggById(size_t id);
    void		resetScale();
  };

}

#endif //PSU_2016_ZAPPY_MAP_HPP
