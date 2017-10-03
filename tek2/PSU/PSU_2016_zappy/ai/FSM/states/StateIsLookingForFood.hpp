/*
** StateLookingForFood.h for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/states/StateLookingForFood.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 15:15:15 2017 Anas Buyumad
** Last update Thu Jun 22 15:15:16 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_STATELOOKINGFORFOOD_H
#define PSU_2016_ZAPPY_STATELOOKINGFORFOOD_H

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai {
  struct StateIsLookingForFood : msmf::state<>
  {
    template <class Event, class Fsm>
    void on_entry(Event const &event, Fsm &machine) const {
      std::cout << "StateIsLookingForFood::on_entry()" << std::endl;

      /*
       * IsLookingForFood
       *
       * Gets Vision to check is food is present on cell, and for MoveTowardsFood.
       *
       * Check if food is present on cell in guards.
       */

      machine.isCallingForIncantation = false;

      auto	vision = IOStreamHandler::get().getResponseHandler().requestVision();

      if (!vision->getStatus()) {
	IOStreamHandler::get().abortConnection("Invalid Vision Response");
      }

      machine.vision = vision->getValue();

      if (machine.vision.front().player > 1) {

	auto direction = static_cast<Direction>(ai::Random::get()(static_cast<int>(Direction::UP), static_cast<int>(Direction::RIGHT)));

	auto Response = IOStreamHandler::get().getResponseHandler().requestAction(ai::serverDirections.at(direction));

	if (!Response->getStatus()) {
	  IOStreamHandler::get().abortConnection("StateIsLookingForFood :: Invalid Move Response");
	}
	this->on_entry(event, machine);
      }
    }
    template <class Event, class Fsm>
    void on_exit(Event const &, Fsm &) const { std::cout << "StateIsLookingForFood::on_exit()" << std::endl; }
  };
}

#endif //PSU_2016_ZAPPY_STATELOOKINGFORFOOD_H