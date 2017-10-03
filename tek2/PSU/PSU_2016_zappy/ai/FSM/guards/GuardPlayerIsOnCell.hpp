/*
** GuardPlayerIsOnCell.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/guards/GuardPlayerIsOnCell.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 16:51:25 2017 Anas Buyumad
** Last update Thu Jun 22 16:51:26 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_GUARDPLAYERISONCELL_HPP
#define PSU_2016_ZAPPY_GUARDPLAYERISONCELL_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai
{
  struct GuardPlayerIsOnCell
  {
    template <class Fsm,class Evt,class SourceState,class TargetState>
    bool operator()(Evt const& , Fsm& fsm, SourceState& ,TargetState&)
    {
      std::cout << "GuardPlayerIsOnCell::on_guard()" <<  std::endl;
      return fsm.vision.size() > 0 && fsm.vision.front().player > 1;
    }
  };
}

#endif //PSU_2016_ZAPPY_GUARDPLAYERISONCELL_HPP
