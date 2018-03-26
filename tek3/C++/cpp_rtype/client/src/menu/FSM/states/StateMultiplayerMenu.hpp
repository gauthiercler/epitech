#ifndef CPP_RTYPE_STATEMULTIPLAYERMENU_HPP
# define CPP_RTYPE_STATEMULTIPLAYERMENU_HPP

#include <iostream>
#include "State.hpp"

namespace rtype {
  namespace menu {
    namespace FSM {

      struct StateMultiplayerMenu : msmf::state<>, State {

	explicit StateMultiplayerMenu() : State(StateType::MULTIPLAYER) {}

	template<class Event, class Fsm>
	void on_entry(Event const &, Fsm &) const {
	  std::cout << "StateMultiplayerMenu::on_entry()" << std::endl;
	}

	template<class Event, class Fsm>
	void on_exit(Event const &, Fsm &) const {
	  std::cout << "StateMultiplayerMenu::on_exit()" << std::endl;
	}
      };

    }
  }
}

#endif /* !CPP_RTYPE_STATEMULTIPLAYERMENU_HPP*/
