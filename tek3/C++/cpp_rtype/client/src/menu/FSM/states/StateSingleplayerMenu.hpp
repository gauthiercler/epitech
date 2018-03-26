#ifndef CPP_RTYPE_STATESINGLEPLAYERMENU_HPP
# define CPP_RTYPE_STATESINGLEPLAYERMENU_HPP

#include <iostream>
#include "State.hpp"

namespace rtype {
  namespace menu {
    namespace FSM {

      struct StateSingleplayerMenu : msmf::state<>, State {

	explicit StateSingleplayerMenu() : State(StateType::SINGLEPLAYER) {}

	template<class Event, class Fsm>
	void on_entry(Event const &, Fsm &) const {
	  std::cout << "StateSingleplayerMenu::on_entry()" << std::endl;
	}

	template<class Event, class Fsm>
	void on_exit(Event const &, Fsm &) const {
	  std::cout << "StateSingleplayerMenu::on_exit()" << std::endl;
	}
      };

    }
  }
}

#endif /* !CPP_RTYPE_STATESINGLEPLAYERMENU_HPP*/
