#ifndef CPP_RTYPE_STATEMULTIPLAYERLOBBIESLISTINGMENU_HPP
# define CPP_RTYPE_STATEMULTIPLAYERLOBBIESLISTINGMENU_HPP

#include <iostream>
#include "State.hpp"

namespace rtype {
  namespace menu {
    namespace FSM {

      struct StateMultiplayerLobbiesListingMenu : msmf::state<>, State {

	explicit StateMultiplayerLobbiesListingMenu() : State(
	  StateType::MULTIPLAYER_LOBBIES_LIST) {}

	template<class Event, class Fsm>
	void on_entry(Event const &, Fsm &) const {
	  std::cout << "StateMultiplayerLobbiesListingMenu::on_entry()"
		    << std::endl;
	}

	template<class Event, class Fsm>
	void on_exit(Event const &, Fsm &) const {
	  std::cout << "StateMultiplayerLobbiesListingMenu::on_exit()"
		    << std::endl;
	}
      };

    }
  }
}

#endif /* !CPP_RTYPE_STATEMULTIPLAYERLOBBIESLISTINGMENU_HPP*/
