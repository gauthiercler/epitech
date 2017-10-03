/*
** StateHasEnoughStones.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/states/StateHasEnoughStones.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 15:23:56 2017 Anas Buyumad
** Last update Thu Jun 22 15:23:56 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_STATEISCHECKINGSTONE_HPP
#define PSU_2016_ZAPPY_STATEISCHECKINGSTONES_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai {
  struct StateIsCheckingStones : msmf::state<>
  {
    template <class Event, class Fsm>
    void on_entry(Event const &, Fsm &) const { std::cout << "StateIsCheckingStones::on_entry()" << std::endl; }
    template <class Event, class Fsm>
    void on_exit(Event const &, Fsm &) const { std::cout << "StateIsCheckingStones::on_exit()" << std::endl; }
  };
}

#endif //PSU_2016_ZAPPY_STATEISCHECKNGSTONES_HPP
