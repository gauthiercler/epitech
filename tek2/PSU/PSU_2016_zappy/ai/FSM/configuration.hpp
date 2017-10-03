/*
** configuration.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/configuration.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 29 09:18:56 2017 Anas Buyumad
** Last update Thu Jun 29 09:18:56 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_CONFIGURATION_HPP
#define PSU_2016_ZAPPY_CONFIGURATION_HPP

#include	<map>
#include	"classes/AResponse.hpp"

#define FOOD_TIME 	126
#define SELF_POSITION	0

namespace ai {

  const std::map<ResponseType, unsigned int> actionTime = {
    {ResponseType::INVENTORY, 1},
    {ResponseType::TAKE_OBJECT, 7},
    {ResponseType::SET_OBJECT, 7},
    {ResponseType::TURN_LEFT, 7},
    {ResponseType::TURN_RIGHT, 7},
    {ResponseType::FORWARD, 7},
    {ResponseType::CONNECT, 0},
    {ResponseType::START_INCANTATION, 300},
    {ResponseType::EJECT, 7},
    {ResponseType::FORK, 42},
    {ResponseType::BROADCAST, 7},
    {ResponseType::LOOK, 7}
  };

  enum class ItemType {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    NONE
  };

  const std::map<ItemType, std::string>	itemList = {
    {ItemType::FOOD, "food"},
    {ItemType::DERAUMERE, "deraumere"},
    {ItemType::LINEMATE, "linemate"},
    {ItemType::MENDIANE, "mendiane"},
    {ItemType::PHIRAS, "phiras"},
    {ItemType::SIBUR, "sibur"},
    {ItemType::THYSTAME, "thystame"}
  };

  enum class Direction {
    UP = 0,
    LEFT,
    RIGHT,
    RANDOM,
    NONE
  };

  enum class BroadcastMessageType {
    START_INCANTATION,
    END_INCANTATION
  };

  const std::map<BroadcastMessageType, std::string> messagesList = {
    {ai::BroadcastMessageType::START_INCANTATION, "StartIncantation"},
    {ai::BroadcastMessageType::END_INCANTATION, "EndIncantation"}
  };

  const std::map<ai::Direction, ai::ResponseType>	serverDirections = {
    {ai::Direction::UP, ai::ResponseType::FORWARD},
    {ai::Direction::LEFT, ai::ResponseType::TURN_LEFT},
    {ai::Direction::RIGHT, ai::ResponseType::TURN_RIGHT}
  };

  const std::map<unsigned int, unsigned int> neededFoods = {
    {0, 0},
    {1, 20},
    {2, 25},
    {3, 30},
    {4, 40},
    {5, 50},
    {6, 60},
    {7, 70}
  };

}

#endif //PSU_2016_ZAPPY_CONFIGURATION_HPP
