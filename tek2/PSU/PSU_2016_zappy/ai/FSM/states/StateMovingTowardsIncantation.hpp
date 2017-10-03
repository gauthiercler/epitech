/*
** StateMovingTowardsIncantation.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/states/StateMovingTowardsIncantation.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 15:34:48 2017 Anas Buyumad
** Last update Thu Jun 22 15:34:49 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_STATEMOVINGTOWARDSINCANTATION_HPP
#define PSU_2016_ZAPPY_STATEMOVINGTOWARDSINCANTATION_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai {
  struct StateMovingTowardsIncantation : msmf::state<>
  {
    template <class Event, class Fsm>
    void on_entry(Event const &, Fsm &machine) const {
      std::cout << "StateMovingTowardsIncantation::on_entry()" << std::endl;

      /*
       * State :: MovingTowardsIncantation
       *
       * Gets direction of move action with DistanceCalculator
       *
       *
       *
       *
       *
       */



      ai::DistanceCalculator::BroadcastMoveAction	action = ai::DistanceCalculator::getDirectionToIncantation(machine.incantationCall.origin);

      machine.direction = (action == ai::DistanceCalculator::BroadcastMoveAction::MOVE_FORWARD ? Direction::UP : Direction::NONE);
      if (action == ai::DistanceCalculator::BroadcastMoveAction::MOVE_FORWARD ||
	action == ai::DistanceCalculator::BroadcastMoveAction::DO_NOTHING) {
	machine.orientation = Direction::NONE;
      }
      else {
	machine.orientation = (action == ai::DistanceCalculator::BroadcastMoveAction::TURN_LEFT ? Direction::LEFT : Direction::RIGHT);
      }
      machine.incantationCall.origin = SELF_POSITION;
    }
    template <class Event, class Fsm>
    void on_exit(Event const &, Fsm &) const { std::cout << "StateMovingTowardsIncantation::on_exit()" << std::endl; }
  };
}

#endif //PSU_2016_ZAPPY_STATEMOVINGTOWARDSINCANTATION_HPP
