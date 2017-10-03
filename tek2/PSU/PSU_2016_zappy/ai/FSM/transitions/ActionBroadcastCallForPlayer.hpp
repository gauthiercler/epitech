/*
** ActionBroadcastCallForPlayer.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/FSM/transitions/ActionBroadcastCallForPlayer.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jun 23 10:43:55 2017 Gauthier Cler
** Last update Fri Jun 23 10:43:55 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_ACTIONBROADCASTCALLFORPLAYER_HPP
# define PSU_2016_ZAPPY_ACTIONBROADCASTCALLFORPLAYER_HPP

#include <iostream>

namespace ai {
  struct ActionBroadcastCallForPlayer {
    template <class Event, class Fsm, class SourceState, class TargetState>
    void operator()(Event const&, Fsm&fsm, SourceState&, TargetState&) const
    {
      fsm.isCallingForIncantation = true;
      std::cout << "ActionBroadcastCallForPlayer()" << std::endl;
      std::cout << "////////////////////////////////////" << std::endl;
      std::cout << "////////////////////////////////////" << std::endl;
      std::cout << "CALLING FOR INCANTATION" << std::endl;
      std::cout << "////////////////////////////////////" << std::endl;
      std::cout << "////////////////////////////////////" << std::endl;
      auto response = IOStreamHandler::get().getResponseHandler().broadcastMessage(fsm.teamName,
										   BroadcastMessageType::START_INCANTATION,
										   fsm.level);
      if (!response->getStatus()) {
	IOStreamHandler::get().abortConnection(
	  "ActionBroadcastCallForPlayer :: Invalid Response");
      }
      fsm.nbCallsForIncantation += 1;
    }
  };
}

#endif /* !PSU_2016_ZAPPY_ACTIONBROADCASTCALLFORPLAYER_HPP*/
