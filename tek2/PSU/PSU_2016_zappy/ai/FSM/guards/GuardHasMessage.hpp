/*
** GuardHasMessage.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/FSM/guards/GuardHasMessage.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 22 16:47:21 2017 Anas Buyumad
** Last update Thu Jun 22 16:47:21 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_GUARDHASMESSAGE_HPP
#define PSU_2016_ZAPPY_GUARDHASMESSAGE_HPP

#include <iostream>
#include "FSM/definitions.hpp"

namespace ai
{
  struct GuardHasMessage
  {
    template <class Fsm,class Evt,class SourceState,class TargetState>
    bool operator()(Evt const& , Fsm &machine , SourceState& ,TargetState&)
    {
      std::cout << "GuardHasMessage::on_guard()" <<  std::endl;
      while (IOStreamHandler::get().getResponseHandler().getReceivedMessages().size()) {
	auto response = IOStreamHandler::get().getResponseHandler().getBroadcastMessage();

	if (!response->getStatus()) {
	  IOStreamHandler::get().abortConnection("Invalid broadcast message");
	}

	if (machine.isCallingForIncantation && machine.canFork)
	  return false;

	auto message = response->getValue();

	if (message.level != machine.level + 1 || message.teamName != machine.teamName)
	  continue;

	if (machine.seekIncantation && message.type == Broadcast::END && message.origin == SELF_POSITION) {
	  std::cout << "Machine level up after end of broadcast at self position" << std::endl;
	  machine.level += 1;
	  machine.canFork = false;
	  std::cout << "***************************************************" << std::endl;
	  std::cout << "***************************************************" << std::endl;
	  std::cerr << "LEVEL UP TO LEVEL " << machine.level << " From Message" << std::endl;
	  std::cout << "***************************************************" << std::endl;
	  std::cout << "***************************************************" << std::endl;
	  machine.seekIncantation = !machine.seekIncantation;
	}
	else if (message.type == Broadcast::START && message.level == machine.level + 1) {
	  std::cout << "Rallying to Incantation call" << std::endl;
	  std::cout << "Team :: " << message.teamName << std::endl;
	  std::cout << "Origin :: " << message.origin << std::endl;
	  std::cout << "Level :: " << message.level << std::endl;
	  std::cout << "<--------------------->" << std::endl;
	  machine.incantationCall = message;
	  if (!machine.seekIncantation) {
	    machine.nbSeeksForIncantation = 0;
	    machine.seekIncantation = true;
	  }
	  else {
	    machine.nbSeeksForIncantation += 1;
	    if (machine.nbSeeksForIncantation >= (machine.mapSize.first + machine.mapSize.second) / 2 * 3) {
	      machine.seekIncantation = false;
	    }
	  }
	}
      }
      return machine.seekIncantation;
    }
  };
}

#endif //PSU_2016_ZAPPY_GUARDHASMESSAGE_HPP