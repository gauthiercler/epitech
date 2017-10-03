/*
** GuardHasEnoughFood.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/guards/GuardHasEnoughFood.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 16:30:14 2017 Anas Buyumad
** Last update Thu Jun 22 16:30:14 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_GUARDHASENOUGHFOOD_HPP
#define PSU_2016_ZAPPY_GUARDHASENOUGHFOOD_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai
{
  struct GuardHasEnoughFood
  {
    template <class Fsm,class Evt,class SourceState,class TargetState>
    bool operator()(Evt const& , Fsm&machine , SourceState& ,TargetState&)
    {
      unsigned int foodRequired = ai::neededFoods.at(machine.level);
      std::cout << "GuardHasEnoughFood::on_guard()" <<  std::endl;
      if (machine.seekFood && machine.inventory.food < foodRequired)
	return false;
      if (machine.inventory.food >= foodRequired - (foodRequired - 10)) {
	if (machine.inventory.food >= foodRequired)
	  machine.seekFood = false;
	return true;
      }
      machine.seekFood = true;
      return false;
    }
  };
}

#endif //PSU_2016_ZAPPY_GUARDHASENOUGHFOOD_HPP
