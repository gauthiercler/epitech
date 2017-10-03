/*
** GuardHasEnoughPlayersOnTeam.hpp for PSU_2016_zappy in /home/gogo/PSU_2016_zappy/ai/FSM/guards/GuardHasEnoughPlayersOnTeam.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Jul 01 00:28:08 2017 Gauthier Cler
** Last update Sat Jul 01 00:28:08 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_GUARDHASENOUGHPLAYERSONTEAM_HPP
# define PSU_2016_ZAPPY_GUARDHASENOUGHPLAYERSONTEAM_HPP

#include <iostream>
#include <FSM/configuration.hpp>
#include <classes/LevelRequirement.hpp>
#include "FSM/definitions.hpp"

namespace ai
{
  struct GuardPlayersCallForIncantationTimeout
  {
    template <class Fsm,class Evt,class SourceState,class TargetState>
    bool operator()(Evt const& , Fsm &machine , SourceState& ,TargetState&)
    {
      std::cout << "GuardPlayersCallForIncantationTimeout::on_guard()" <<  std::endl;

      return !(machine.nbCallsForIncantation > (machine.mapSize.first + machine.mapSize.second) / 2 * 3);
    }
  };
}

#endif /* !PSU_2016_ZAPPY_GUARDHASENOUGHPLAYERSONTEAM_HPP*/
