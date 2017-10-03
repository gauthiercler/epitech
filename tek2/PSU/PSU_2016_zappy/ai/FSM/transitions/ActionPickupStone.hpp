/*
** ActionPickupStone.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/FSM/transitions/ActionPickupStone.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jun 23 10:40:40 2017 Gauthier Cler
** Last update Fri Jun 23 10:40:40 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_ACTIONPICKUPSTONE_HPP
# define PSU_2016_ZAPPY_ACTIONPICKUPSTONE_HPP

#include <iostream>
#include <classes/IOStreamHandler.hpp>

namespace ai {

  struct ActionPickupStone {

    template <class Fsm>
    ItemType		getItemToPick(Fsm &fsm) const {

      if (fsm.neededItems.linemate >= 0 && fsm.vision.front().content.linemate > 0) return ItemType::LINEMATE;
      if (fsm.neededItems.deraumere >= 0 && fsm.vision.front().content.deraumere > 0) return ItemType::DERAUMERE;
      if (fsm.neededItems.sibur >= 0 && fsm.vision.front().content.sibur > 0) return ItemType::SIBUR;
      if (fsm.neededItems.mendiane >= 0 && fsm.vision.front().content.mendiane > 0) return ItemType::MENDIANE;
      if (fsm.neededItems.phiras >= 0 && fsm.vision.front().content.phiras > 0) return ItemType::PHIRAS;
      if (fsm.neededItems.thystame >= 0 && fsm.vision.front().content.thystame > 0) return ItemType::THYSTAME;
      return ItemType::NONE;
    }

    template <class Event, class Fsm, class SourceState, class TargetState>
    void operator()(Event const&, Fsm& fsm, SourceState&, TargetState&) const
    {
      std::cout << "ActionPickupStone()" << std::endl;

      ItemType type = this->getItemToPick(fsm);
      if (type != ItemType::NONE) {
	auto response = IOStreamHandler::get().getResponseHandler().requestObjectAction(ResponseType::TAKE_OBJECT, type);

	if (!response->getStatus()) {
	  IOStreamHandler::get().abortConnection(
	    "ActionPickupStone :: Invalid Take Stone Response");
	}
      }
    }
  };
}

#endif /* !PSU_2016_ZAPPY_ACTIONPICKUPSTONE_HPP*/
