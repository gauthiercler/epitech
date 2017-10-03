/*
** ActionStartIncantation.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/FSM/transitions/ActionStartIncantation.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jun 23 10:42:21 2017 Gauthier Cler
** Last update Fri Jun 23 10:42:21 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_ACTIONSTARTINCANTATION_HPP
# define PSU_2016_ZAPPY_ACTIONSTARTINCANTATION_HPP

#include <iostream>

namespace ai {
  struct ActionStartIncantation {
    template <class Event, class Fsm, class SourceState, class TargetState>
    void operator()(Event const&, Fsm&fsm, SourceState&, TargetState&) const
    {
      std::cout << "ActionStartIncantation()" << std::endl;

      auto response = IOStreamHandler::get().getResponseHandler().requestIncantation(ResponseType::START_INCANTATION);
      if (!response->getStatus()) {
	IOStreamHandler::get().abortConnection(
	  "ActionStartIncantation :: Invalid First Response");
      }
      auto responseEnd = IOStreamHandler::get().getResponseHandler().requestIncantation(ResponseType::END_INCANTATION);
      if (!responseEnd->getStatus()) {
	IOStreamHandler::get().abortConnection(
	  "ActionStartIncantation :: Invalid Second Response");
      }

      if (response->getValue() && responseEnd->getValue()) {

	if (fsm.level > 1) {
	  auto responseBroadcast = IOStreamHandler::get().getResponseHandler().broadcastMessage(fsm.teamName,
												BroadcastMessageType::END_INCANTATION,
												fsm.level);
	  if (!responseBroadcast->getStatus()) {
	    IOStreamHandler::get().abortConnection(
	      "ActionStartIncantation :: Invalid Broadcast Response");
	  }
	}
	fsm.level += 1;
	fsm.canFork = !(fsm.level == 3 || fsm.level == 5 || fsm.level == 7);
	std::cout << "***************************************************" << std::endl;
	std::cout << "***************************************************" << std::endl;
	std::cerr << "LEVEL UP TO LEVEL " << fsm.level << std::endl;
	std::cout << "***************************************************" << std::endl;
	std::cout << "***************************************************" << std::endl;
      }
      else {
	std::cerr << "Fail incantation of level :" << fsm.level + 1 << std::endl;
      }
    }
  };
}

#endif /* !PSU_2016_ZAPPY_ACTIONSTARTINCANTATION_HPP*/
