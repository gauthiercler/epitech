/*
** StateMovingTowardsFood.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/states/StateMovingTowardsFood.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Jun 28 16:32:08 2017 Anas Buyumad
** Last update Wed Jun 28 16:32:08 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_STATEMOVINGTOWARDSFOOD_HPP
#define PSU_2016_ZAPPY_STATEMOVINGTOWARDSFOOD_HPP

#include <iostream>
#include "FSM/definitions.hpp"
#include "FSM/DistanceCalculator.hpp"

namespace ai {
  struct StateMovingTowardsFood : msmf::state<>
  {
    template <class Event, class Fsm>
    void on_entry(Event const &, Fsm &machine) const {
      std::cout << "StateMovingTowardsFood::on_entry()" << std::endl;

      /*
       * State :: MovingTowardsFood
       *
       * Food is either somewhere in the vision, or nowhere at all.
       * Accordingly, we determine which way to go, to the closest food (maybe use weight in case there are more), or a random direction.
       *
       * Action move will be called when returning to the initial state.
       *
       */

      std::vector<ai::DistanceCalculator::Node>		nodes;
      size_t						index = 0;

      for (auto &&cell : machine.vision) {
	if (cell.content.food && cell.player == 0) {
	  ai::DistanceCalculator::NodeRPosition nodePosition = ai::DistanceCalculator::getDistance(index);
	  nodes.push_back({index, cell.content.food, static_cast<double>(cell.content.food) / static_cast<double>(nodePosition.distance), nodePosition});
	}
	index += 1;
      }

      if (nodes.size()) {
	auto node =  std::max_element(nodes.begin(), nodes.end(), [](const ai::DistanceCalculator::Node &node1, const ai::DistanceCalculator::Node &node2) { return node1.weight < node2.weight; });

	machine.direction = Direction::UP;
	if (node->relativePosition.forthDistance == 1 && node->relativePosition.direction != ai::DistanceCalculator::NodeRDirection::FORWARD) {
	  machine.orientation = (node->relativePosition.direction == ai::DistanceCalculator::NodeRDirection::LEFT ? Direction::LEFT : Direction::RIGHT);
	}
      }

    }
    template <class Event, class Fsm>
    void on_exit(Event const &, Fsm &) const { std::cout << "StateMovingTowardsFood::on_exit()" << std::endl; }
  };
}

#endif //PSU_2016_ZAPPY_STATEMOVINGTOWARDSFOOD_HPP
