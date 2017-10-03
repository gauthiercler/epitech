/*
** StateRemovingStone.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/states/StateRemovingStone.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 15:30:10 2017 Anas Buyumad
** Last update Thu Jun 22 15:30:10 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_STATEREMOVINGSTONE_HPP
#define PSU_2016_ZAPPY_STATEREMOVINGSTONE_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai {
  struct StateRemovingStone : msmf::state<>
  {
    template <class Event, class Fsm>
    void on_entry(Event const &, Fsm &) const { std::cout << "StateRemovingStone::on_entry()" << std::endl; }
    template <class Event, class Fsm>
    void on_exit(Event const &, Fsm &) const { std::cout << "StateRemovingStone::on_exit()" << std::endl; }
  };
}

#endif //PSU_2016_ZAPPY_STATEREMOVINGSTONE_HPP
