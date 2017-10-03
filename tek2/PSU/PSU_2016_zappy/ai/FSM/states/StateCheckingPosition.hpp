/*
** StateCheckingPosition.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/states/StateCheckingPosition.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 15:34:15 2017 Anas Buyumad
** Last update Thu Jun 22 15:34:15 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_STATECHECKINGPOSITION_HPP
#define PSU_2016_ZAPPY_STATECHECKINGPOSITION_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai {
  struct StateCheckingPosition : msmf::state<>
  {
    template <class Event, class Fsm>
    void on_entry(Event const &, Fsm &machine) const {
      std::cout << "StateCheckingPosition::on_entry()" << std::endl;

      /*
       * State :: CheckingPosition
       *
       * Will be checking whether machine is on correct cell for ongoing incantation.
       * Should be checked on guard, nothing to do here.
       *
       *
       * Gets vision for when we move towards it, so that we can check if we should cancel the incantation
       *
       */

      std::cout << "Checking position of incantation of level " << machine.incantationCall.level << std::endl;
    }
    template <class Event, class Fsm>
    void on_exit(Event const &, Fsm &) const { std::cout << "StateCheckingPosition::on_exit()" << std::endl; }
  };
}

#endif //PSU_2016_ZAPPY_STATECHECKINGPOSITION_HPP
