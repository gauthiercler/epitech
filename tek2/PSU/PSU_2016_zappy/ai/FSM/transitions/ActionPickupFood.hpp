/*
** ActionPickupFood.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/FSM/transitions/ActionPickupFood.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jun 23 10:37:36 2017 Gauthier Cler
** Last update Fri Jun 23 10:37:36 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_ACTIONPICKUPFOOD_HPP
# define PSU_2016_ZAPPY_ACTIONPICKUPFOOD_HPP

#include <iostream>
#include <classes/IOStreamHandler.hpp>

namespace ai {
  struct ActionPickupFood {
    template <class Event, class Fsm, class SourceState, class TargetState>
    void operator()(Event const&, Fsm&, SourceState&, TargetState&) const
    {
      std::cout << "ActionPickupFood()" << std::endl;

      auto response = IOStreamHandler::get().getResponseHandler().requestObjectAction(ResponseType::TAKE_OBJECT, ItemType::FOOD);

      if (!response->getStatus()) {
	IOStreamHandler::get().abortConnection(
	  "ActionPickupFood :: Invalid Take Food Response");
      }
    }
  };
}

#endif /* !PSU_2016_ZAPPY_ACTIONPICKUPFOOD_HPP*/
