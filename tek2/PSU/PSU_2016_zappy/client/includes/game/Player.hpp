/*
** Player.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/game/Player.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 22 09:00:14 2017 Vincent DUSAUTOIR
** Last update Thu Jun 22 09:00:14 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_PLAYER_HPP
#define PSU_2016_ZAPPY_PLAYER_HPP

#include <chrono>
#include "AEntity.hpp"
#include "Inventory.hpp"

namespace zappy {
  enum class Orientation {
    NORTH,
    EAST,
    SOUTH,
    WEST
  };

  class		Player : public AEntity {
    size_t	_id;
    Position	_pos;
    Orientation _orientation;
    size_t	_level;
    std::string	_teamName;
    Inventory	_inventory;
    Sprite	_sprite;
    bool	_broadcasting;
    std::chrono::time_point<std::chrono::system_clock> _last;

  public:
    Player(size_t id, const Position &pos, Orientation orientation, size_t level, const std::string &teamName);
    virtual ~Player();

    virtual void update();

    virtual void render(const Position &offset, const Size &scale);
    void	 move(const Position &position, const Orientation &orientation);
    void	 setLevel(size_t level);
    void	 renderSelected(size_t current, size_t total);
    const Position &getPos() const;
    const size_t &getId() const;
    void setInventory(size_t food, size_t linemate, size_t deraumere, size_t sibur, size_t mendiane, size_t phiras, size_t thystame);
    void sendBroadcast();
  };
}

#endif //PSU_2016_ZAPPY_PLAYER_HPP
