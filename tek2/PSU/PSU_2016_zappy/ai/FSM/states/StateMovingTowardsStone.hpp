/*
** StateMovingTowardsStone.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/states/StateMovingTowardsStone.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Jun 28 17:02:25 2017 Anas Buyumad
** Last update Wed Jun 28 17:02:25 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_STATEMOVINGTOWARDSSTONE_HPP
#define PSU_2016_ZAPPY_STATEMOVINGTOWARDSSTONE_HPP

#include <iostream>
#include "FSM/definitions.hpp"
#include "FSM/DistanceCalculator.hpp"

namespace ai {
  struct StateMovingTowardsStone : msmf::state<>
  {
    template <class Event, class Fsm>
    void on_entry(Event const &, Fsm &machine) const {
      std::cout << "StateMovingTowardsStone::on_entry()" << std::endl;

      /*
       * State :: MovingTowardsStone
       *
       * Stones needed are somewhere in the vision, or nowhere at all.
       * Accordingly, we determine which way to go, to the closest one using a weight or in a random direction.
       * Thystame is very rare and should be a top priority.
       *
       * Action move will be called when returning to the initial state.
       *
       */

      std::vector<ai::DistanceCalculator::Node>		nodes;
      size_t						index = 0;

      Inventory neededStones = ai::LevelRequirement::get()[machine.level + 1].second - machine.inventory;
      std::cout << "Needed Stones : " << neededStones << std::endl;

      for (auto &&cell : machine.vision) {
	double	weight = cell.content.getMatchWeight(neededStones);
	if (weight && index && cell.player == 0) {
	  ai::DistanceCalculator::NodeRPosition nodePosition = ai::DistanceCalculator::getDistance(index);
	  nodes.push_back({index, cell.content.sum(), weight, nodePosition});
	}
	index += 1;
      }

      std::cout << "//////////////////// STONES WEIGHT ////////////////" << std::endl;
      for (auto &&node : nodes) {
	std::cout << "Node Index : " << node.index << " && Weight : " << node.weight << std::endl;
      }

      if (nodes.size()) {
	auto node = std::max_element(nodes.begin(), nodes.end(), [](const ai::DistanceCalculator::Node &node1, const ai::DistanceCalculator::Node &node2) { return node1.weight < node2.weight; } );

	machine.direction = Direction::UP;
	if (node->relativePosition.forthDistance == 1 && node->relativePosition.direction != ai::DistanceCalculator::FORWARD) {
	  machine.orientation = (node->relativePosition.direction == ai::DistanceCalculator::NodeRDirection::LEFT ? Direction::LEFT : Direction::RIGHT);
	}
      }

    }
    template <class Event, class Fsm>
    void on_exit(Event const &, Fsm &) const { std::cout << "StateMovingTowardsStone::on_exit()" << std::endl; }
  };
}

#endif //PSU_2016_ZAPPY_STATEMOVINGTOWARDSSTONE_HPP
