/*
** ActionFork.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/FSM/transitions/ActionFork.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jun 30 16:33:51 2017 Gauthier Cler
** Last update Fri Jun 30 16:33:51 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_ACTIONFORK_HPP
# define PSU_2016_ZAPPY_ACTIONFORK_HPP

#include <iostream>
#include <boost/process/spawn.hpp>
#include <classes/IOStreamHandler.hpp>

namespace ai {
  struct ActionFork {
    template <class Event, class Fsm, class SourceState, class TargetState>
    void operator()(Event const&, Fsm&fsm, SourceState&, TargetState&) const
    {
      std::cout << "ActionFork()" << std::endl;

      fsm.nbCallsForIncantation = 0;

      if (!fsm.canFork)
	return ;

      auto response = IOStreamHandler::get().getResponseHandler().requestAction(ResponseType::FORK);
      if (!response->getStatus()) {
	IOStreamHandler::get().abortConnection(
	  "ActionFork :: Invalid Response");
      }


      std::cerr << "LEVEL " << fsm.level << " FORKING" << std::endl;

      boost::process::spawn(fsm.programName, "-n", fsm.teamName, "-p", fsm.port, "-h", fsm.host);

      auto responseMove = IOStreamHandler::get().getResponseHandler().requestAction(ResponseType::FORWARD);
      if (!responseMove->getStatus()) {
	IOStreamHandler::get().abortConnection(
	  "ActionFork :: Invalid Response of Forward");
      }
      fsm.canFork = false;
    }
  };
}

#endif /* !PSU_2016_ZAPPY_ACTIONFORK_HPP*/
