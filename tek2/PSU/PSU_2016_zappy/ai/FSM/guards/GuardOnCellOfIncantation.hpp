/*
** GuardOnCellOfIncantation.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/guards/GuardOnCellOfIncantation.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 16:58:16 2017 Anas Buyumad
** Last update Thu Jun 22 16:58:16 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_GUARDONCELLOFINCANTATION_HPP
#define PSU_2016_ZAPPY_GUARDONCELLOFINCANTATION_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai
{
  struct GuardOnCellOfIncantation
  {
    template <class Fsm,class Evt,class SourceState,class TargetState>
    bool operator()(Evt const& , Fsm &machine , SourceState& ,TargetState&)
    {
      std::cout << "GuardOnCellOfIncantation::on_guard()" <<  std::endl;
      if (machine.incantationCall.origin == SELF_POSITION) {
	std::cout << "ON CELL FOR INCANTATION" << std::endl;
      }
      else {
	std::cout << "NOT ON CELL FOR INCANTATION" << std::endl;
      }
      return machine.incantationCall.origin == SELF_POSITION;
    }
  };
}

#endif //PSU_2016_ZAPPY_GUARDONCELLOFINCANTATION_HPP
