/*
** ActionMove.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/FSM/transitions/ActionMove.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jun 23 10:35:53 2017 Gauthier Cler
** Last update Fri Jun 23 10:35:53 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_ACTIONMOVE_HPP
# define PSU_2016_ZAPPY_ACTIONMOVE_HPP

#include <iostream>
#include "classes/IOStreamHandler.hpp"
#include "classes/Random.hpp"

namespace ai {
  struct ActionMove {
    template<class Event, class Fsm, class SourceState, class TargetState>
    void operator()(Event const &, Fsm &machine, SourceState &,
		    TargetState &) const {
      std::cout << "ActionMove()" << std::endl;


      Direction direction = machine.direction;

      if (direction != Direction::NONE) {
	if (direction == Direction::RANDOM) {
	  direction = static_cast<Direction>(ai::Random::get()(static_cast<int>(Direction::UP), static_cast<int>(Direction::RIGHT)));
	}

	if (direction != Direction::UP && direction != Direction::LEFT &&
	    direction != Direction::RIGHT) {
	  IOStreamHandler::get().abortConnection(
	    "ActionMove :: Invalid direction");
	}

	auto moveResponse = IOStreamHandler::get().getResponseHandler().requestAction(ai::serverDirections.at(direction));

	if (!moveResponse->getStatus()) {
	  IOStreamHandler::get().abortConnection(
	    "ActionMove :: Invalid Move Response");
	}

	std::cout << "/////////////////////////" << std::endl;
	std::cout << "->   Move to direction :: " << static_cast<int>(direction) << " & Answer : "
		  << moveResponse->getValue() << "   <-" << std::endl;
	std::cout << "/////////////////////////" << std::endl;
      }

      if (machine.orientation != Direction::NONE) {
	std::cout << "Got orientation : " << static_cast<int>(machine.orientation) << std::endl;
	auto turnResponse = IOStreamHandler::get().getResponseHandler().requestAction(ai::serverDirections.at(machine.orientation));

	if (!turnResponse->getStatus()) {
	  IOStreamHandler::get().abortConnection("ActionMove :: Invalid Move Response");
	}
	std::cout << "/////////////////////////" << std::endl;
	std::cout << "Turned to direction :: " << static_cast<int>(machine.orientation) << "& Answer : " << turnResponse->getValue() << std::endl;
	std::cout << "/////////////////////////" << std::endl;
      }
    };
  };
}

#endif /* !PSU_2016_ZAPPY_ACTIONMOVE_HPP*/
