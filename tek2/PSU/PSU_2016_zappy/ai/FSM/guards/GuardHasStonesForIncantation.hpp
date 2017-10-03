/*
** GuardHasStonesForIncantation.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/guards/GuardHasStonesForIncantation.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 16:49:04 2017 Anas Buyumad
** Last update Thu Jun 22 16:49:04 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_GUARDHASSTONESFORINCANTATION_HPP
#define PSU_2016_ZAPPY_GUARDHASSTONESFORINCANTATION_HPP

#include <iostream>
#include <classes/LevelRequirement.hpp>
#include "FSM/definitions.hpp"

namespace ai
{
  struct GuardHasStonesForIncantation
  {
    template <class Fsm,class Evt,class SourceState,class TargetState>
    bool operator()(Evt const& , Fsm& fsm, SourceState& ,TargetState&)
    {
      std::cout << "GuardHasStonesForIncantation::on_guard()" <<  std::endl;
      return fsm.inventory >= ai::LevelRequirement::get()[fsm.level + 1].second;
    }
  };
}

#endif //PSU_2016_ZAPPY_GUARDHASSTONESFORINCANTATION_HPP
