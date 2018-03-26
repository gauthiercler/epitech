#ifndef CPP_RTYPE_STATEMULTIPLAYERLOBBYMENU_HPP
# define CPP_RTYPE_STATEMULTIPLAYERLOBBYMENU_HPP

#include <iostream>
#include "State.hpp"

namespace rtype {
  namespace menu {
    namespace FSM {

      struct StateMultiplayerLobbyMenu : msmf::state<>, State {

	explicit StateMultiplayerLobbyMenu() : State(
	  StateType::MULTIPLAYER_LOBBY) {}

	template<class Event, class Fsm>
	void on_entry(Event const &, Fsm &) const {
		std::cout << "StateMultiplayerLobbyMenu::on_entry()" << std::endl;
	}

	template<class Event, class Fsm>
	void on_exit(Event const &, Fsm &) const {
	  std::cout << "StateMultiplayerLobbyMenu::on_exit()" << std::endl;
	}
      };

    }
  }
}

#endif /* !CPP_RTYPE_STATEMULTIPLAYERLOBBYMENU_HPP*/
