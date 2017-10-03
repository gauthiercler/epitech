/*
** StateCheckFood.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/FSM/states/StateCheckFood.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jun 21 18:23:51 2017 Gauthier Cler
** Last update Wed Jun 21 18:23:51 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_STATEISCHECKINGFOOD_HPP
# define PSU_2016_ZAPPY_STATEISCHECKINGFOOD_HPP

#include <iostream>
#include "FSM/definitions.hpp"
#include "classes/IOStreamHandler.hpp"

namespace ai {
  struct StateIsCheckingFood : msmf::state<>
  {
    template <class Event, class Fsm>
    void on_entry(Event const &, Fsm &machine) const {
      std::cout << "StateIsCheckingFood::on_entry()" << std::endl;

      /*
       * Initial State :: IsCheckingFood
       *
       * Clears Inventory & Vision & Initializes direction to RANDOM as a new turn is ongoing.
       * Gets current inventory and stores it.
       *
       * Current amount of food will be checked in HasEnoughFood Guard Transition.
       *
       */

      machine.vision.clear();
      machine.inventory = Inventory();
      machine.direction = Direction::RANDOM;
      machine.orientation = Direction::NONE;

      auto	inventory = IOStreamHandler::get().getResponseHandler().requestInventory();

      if (!inventory->getStatus()) {
	IOStreamHandler::get().abortConnection("Invalid Inventory Response");
      }

      machine.inventory = inventory->getValue();
      std::cout << "Inventory :: " << machine.inventory << std::endl;
      std::cout << "Current Food :: " << machine.inventory.food << std::endl;
    }
    template <class Event, class Fsm>
    void on_exit(Event const &, Fsm &) const { std::cout << "StateIsCheckingFood::on_exit()" << std::endl; }
  };
}

#endif /* !PSU_2016_ZAPPY_STATEISCHECKINGFOOD_HPP*/