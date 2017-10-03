/*
** GuardEnoughPlayersForIncantation.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/guards/GuardEnoughPlayersForIncantation.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 16:53:10 2017 Anas Buyumad
** Last update Thu Jun 22 16:53:10 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_GUARDENOUGHPLAYERSFORINCANTATION_HPP
#define PSU_2016_ZAPPY_GUARDENOUGHPLAYERSFORINCANTATION_HPP

#include <iostream>
#include <classes/LevelRequirement.hpp>
#include "FSM/definitions.hpp"

namespace ai
{
  struct GuardEnoughPlayersForIncantation
  {
    template <class Fsm,class Evt,class SourceState,class TargetState>
    bool operator()(Evt const& , Fsm& fsm, SourceState& ,TargetState&)
    {
      std::cout << "GuardEnoughPlayersForIncantation::on_guard()" <<  std::endl;
      return fsm.vision.size() > 0 && fsm.vision.front().player == LevelRequirement::get()[fsm.level + 1].first;
    }
  };
}

#endif //PSU_2016_ZAPPY_GUARDENOUGHPLAYERSFORINCANTATION_HPP
