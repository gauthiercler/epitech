/*
** StateStartingIncantation.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/states/StateStartingIncantation.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 15:31:16 2017 Anas Buyumad
** Last update Thu Jun 22 15:31:16 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_STATESTARTINGINCANTATION_HPP
#define PSU_2016_ZAPPY_STATESTARTINGINCANTATION_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai {
  struct StateStartingIncantation : msmf::state<>
  {
    template <class Event, class Fsm>
    void on_entry(Event const &, Fsm &) const { std::cout << "StateStartingIncantation::on_entry()" << std::endl; }
    template <class Event, class Fsm>
    void on_exit(Event const &, Fsm &) const { std::cout << "StateStartingIncantation::on_exit()" << std::endl; }
  };
}

#endif //PSU_2016_ZAPPY_STATESTARTINGINCANTATION_HPP
