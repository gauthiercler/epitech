/*
** StateEnoughPlayers.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/states/StateEnoughPlayers.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 15:27:49 2017 Anas Buyumad
** Last update Thu Jun 22 15:27:49 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_STATEENOUGHPLAYERS_HPP
#define PSU_2016_ZAPPY_STATEENOUGHPLAYERS_HPP

#include <iostream>
#include <FSM/FSM.hpp>
#include "FSM/definitions.hpp"

namespace ai {
  struct StateIsLookingForPlayers : msmf::state<>
  {
    template <class Event, class Fsm>
    void on_entry(Event const &, Fsm &machine) const {
      std::cout << "StateIsLookingForPlayers::on_entry()" << std::endl;

      auto	vision = IOStreamHandler::get().getResponseHandler().requestVision();

      if (!vision->getStatus()) {
	IOStreamHandler::get().abortConnection("Invalid Vision Response");
      }

      std::cout << "->   Vision   <-" << std::endl;
      machine.vision = vision->getValue();
      for (auto &&cell : machine.vision) {
	std::cout << "-> " << cell << std::endl;
      }
    }
    template <class Event, class Fsm>
    void on_exit(Event const &, Fsm &) const { std::cout << "StateIsLookingForPlayers::on_exit()" << std::endl; }
  };
}

#endif //PSU_2016_ZAPPY_STATEENOUGHPLAYERS_HPP
