/*
** GuardExactStonesOnCellForIncantation.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/guards/GuardExactStonesOnCellForIncantation.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 16:55:11 2017 Anas Buyumad
** Last update Thu Jun 22 16:55:13 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_GUARDEXACTSTONESONCELLFORINCANTATION_HPP
#define PSU_2016_ZAPPY_GUARDEXACTSTONESONCELLFORINCANTATION_HPP

#include <iostream>
#include <classes/LevelRequirement.hpp>
#include "FSM/definitions.hpp"

namespace ai
{
  struct GuardExactStonesOnCellForIncantation
  {
    template <class Fsm,class Evt,class SourceState,class TargetState>
    bool operator()(Evt const& , Fsm& fsm, SourceState& ,TargetState&)
    {
      std::cout << "GuardExactStonesOnCellForIncantation::on_guard()" <<  std::endl;
      return fsm.vision.size() > 0 && fsm.vision.front().content == ai::LevelRequirement::get()[fsm.level + 1].second;
    }
  };
}

#endif //PSU_2016_ZAPPY_GUARDEXACTSTONESONCELLFORINCANTATION_HPP
