/*
** GuardStoneIsOnCell.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/guards/GuardStoneIsOnCell.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 16:50:37 2017 Anas Buyumad
** Last update Thu Jun 22 16:50:37 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_GUARDSTONEISONCELL_HPP
#define PSU_2016_ZAPPY_GUARDSTONEISONCELL_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai
{
  struct GuardStoneIsOnCell
  {
    template <class Fsm,class Evt,class SourceState,class TargetState>
    bool operator()(Evt const& , Fsm& fsm, SourceState& ,TargetState&)
    {
      std::cout << "GuardStoneIsOnCell::on_guard()" <<  std::endl;
      if (fsm.neededItems.linemate >= 0 && fsm.vision.front().content.linemate > 0) return true;
      if (fsm.neededItems.deraumere >= 0 && fsm.vision.front().content.deraumere > 0) return true;
      if (fsm.neededItems.sibur >= 0 && fsm.vision.front().content.sibur > 0) return true;
      if (fsm.neededItems.mendiane >= 0 && fsm.vision.front().content.mendiane > 0) return true;
      if (fsm.neededItems.phiras >= 0 && fsm.vision.front().content.phiras > 0) return true;
      if (fsm.neededItems.thystame >= 0 && fsm.vision.front().content.thystame > 0) return true;
      return false;
    }
  };
}

#endif //PSU_2016_ZAPPY_GUARDSTONEISONCELL_HPP
