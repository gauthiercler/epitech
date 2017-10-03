/*
** DistanceCalculator.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/DistanceCalculator.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 29 19:11:50 2017 Anas Buyumad
** Last update Thu Jun 29 19:11:50 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_DISTANCECALCULATOR_HPP
#define PSU_2016_ZAPPY_DISTANCECALCULATOR_HPP

#include <utility>
#include <iostream>
#include <cstddef>

namespace ai {

  namespace DistanceCalculator {

    enum NodeRDirection {
      FORWARD = 0,
      LEFT,
      RIGHT
    };

    struct NodeRPosition {

      size_t forthDistance;
      size_t sideDistance;
      size_t distance;
      NodeRDirection direction;
    };

    struct Node {

      size_t index;
      size_t quantity;
      double weight;
      NodeRPosition relativePosition;
    };

    inline void
    assessNewBounds(std::pair<size_t, size_t> &bounds, size_t coefficient) {
      bounds.first = bounds.second + 1;
      bounds.second = bounds.first + 2 * coefficient;
    }

    static NodeRPosition getDistance(size_t index) {
      size_t forthDistance = 1;
      std::pair<size_t, size_t> bounds = {1, 3};

      for (;;) {
	for (size_t iterator = bounds.first; iterator <= bounds.second; ++iterator) {
	  if (iterator == index) {
	    int			delta = static_cast<int>(iterator) - static_cast<int>((bounds.first + bounds.second) / 2);
	    size_t		sideDistance = static_cast<size_t>(std::abs(delta));
	    NodeRDirection	direction =
	      delta == 0 ? NodeRDirection::FORWARD :
	      (delta < 0 ? NodeRDirection::LEFT : NodeRDirection::RIGHT);
	    return {forthDistance, sideDistance, forthDistance + sideDistance, direction};
	  }
	}
	forthDistance += 1;
	assessNewBounds(bounds, forthDistance);
      }
    }

    enum BroadcastMoveAction {
      MOVE_FORWARD = 0,
      TURN_LEFT,
      TURN_RIGHT,
      DO_NOTHING
    };

    static std::map<size_t, BroadcastMoveAction>	soundDirection = {
      {0, DO_NOTHING},
      {1, MOVE_FORWARD},
      {2, MOVE_FORWARD},
      {3, TURN_LEFT},
      {4, TURN_LEFT},
      {5, TURN_LEFT},
      {6, TURN_RIGHT},
      {7, TURN_RIGHT},
      {8, MOVE_FORWARD}
    };

    static BroadcastMoveAction getDirectionToIncantation(size_t origin) {
      return soundDirection.at(origin);
    }

  }
}

#endif //PSU_2016_ZAPPY_DISTANCECALCULATOR_HPP
