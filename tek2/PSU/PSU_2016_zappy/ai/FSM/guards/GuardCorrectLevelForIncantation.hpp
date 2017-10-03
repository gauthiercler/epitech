/*
** GuardCorrectLevelForIncantation.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/guards/GuardCorrectLevelForIncantation.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 16:56:18 2017 Anas Buyumad
** Last update Thu Jun 22 16:56:19 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_GUARDCORRECTLEVELFORINCANTATION_HPP
#define PSU_2016_ZAPPY_GUARDCORRECTLEVELFORINCANTATION_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai
{
  struct GuardCorrectLevelForIncantation
  {
    template <class Fsm,class Evt,class SourceState,class TargetState>
    bool operator()(Evt const& , Fsm& , SourceState& ,TargetState&)
    {
      std::cout << "GuardCorrectLevelForIncantation::on_guard()" <<  std::endl;
      return false;
    }
  };
}

#endif //PSU_2016_ZAPPY_GUARDCORRECTLEVELFORINCANTATION_HPP
