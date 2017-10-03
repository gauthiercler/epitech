/*
** GuardFoodIsOnCell.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/guards/GuardFoodIsOnCell.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 16:45:09 2017 Anas Buyumad
** Last update Thu Jun 22 16:45:09 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_GUARDFOODISONCELL_HPP
#define PSU_2016_ZAPPY_GUARDFOODISONCELL_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai
{
  struct GuardFoodIsOnCell
  {
    template <class Fsm,class Evt,class SourceState,class TargetState>
    bool operator()(Evt const& , Fsm &machine, SourceState& ,TargetState&)
    {
      std::cout << "GuardFoodIsOnCell::on_guard()" <<  std::endl;
      return machine.vision.at(SELF_POSITION).content.food;
    }
  };
}

#endif //PSU_2016_ZAPPY_GUARDFOODISONCELL_HPP
