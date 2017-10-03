/*
** StatePickupStone.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/states/StatePickupStone.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 15:25:31 2017 Anas Buyumad
** Last update Thu Jun 22 15:25:32 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_STATELOOKINGFORSTONES_HPP
#define PSU_2016_ZAPPY_STATELOOKINGFORSTONES_HPP

#include <iostream>
#include <FSM/FSM.hpp>
#include "FSM/definitions.hpp"

namespace ai {
  struct StateisLookingForStones : msmf::state<>
  {
    Inventory getitemToPick(Inventory &inventory, unsigned int &level) const {
      auto needed = ai::LevelRequirement::get()[level + 1].second;

      return needed - inventory;
    }

    template <class Event, class Fsm>
    void on_entry(Event const &event, Fsm &machine) const {
      std::cout << "StateisLookingForStones::on_entry()" << std::endl;

      auto	vision = IOStreamHandler::get().getResponseHandler().requestVision();

      if (!vision->getStatus()) {
	IOStreamHandler::get().abortConnection("Invalid Vision Response");
      }

//      std::cout << "->   Vision   <-" << std::endl;
      machine.vision = vision->getValue();
      machine.neededItems = this->getitemToPick(machine.inventory, machine.level);

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
    void on_exit(Event const &, Fsm &) const { std::cout << "StateisLookingForStones::on_exit()" << std::endl; }
  };
}

#endif //PSU_2016_ZAPPY_STATELOOKINGFORSTONES_HPP
