/*
** StateFoodOnCell.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/states/StateFoodOnCell.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 15:16:59 2017 Anas Buyumad
** Last update Thu Jun 22 15:17:00 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_STATEFOODONCELL_HPP
#define PSU_2016_ZAPPY_STATEFOODONCELL_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai {
  struct StateFoodIsOnCell : msmf::state<>
  {
    template <class Event, class Fsm>
    void on_entry(Event const &, Fsm &) const {
      std::cout << "StateFoodIsOnCell::on_entry()" << std::endl;

      /*
       * State :: FoodIsOnCell
       *
       * Food is present at the current position.
       * It will be picked up when going through the PickUpFood Action Transition.
       *
       * Nothing should be done here.
       *
       */
    }
    template <class Event, class Fsm>
    void on_exit(Event const &, Fsm &) const { std::cout << "StateFoodIsOnCell::on_exit()" << std::endl; }
  };
}

#endif //PSU_2016_ZAPPY_STATEFOODONCELL_HPP
