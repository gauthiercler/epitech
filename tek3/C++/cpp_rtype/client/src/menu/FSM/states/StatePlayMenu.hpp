#ifndef CPP_RTYPE_STATEPLAYMENU_HPP
# define CPP_RTYPE_STATEPLAYMENU_HPP

#include <iostream>
#include "State.hpp"

namespace rtype {
  namespace menu {
    namespace FSM {

      struct StatePlayMenu : msmf::state<>, State {

	explicit StatePlayMenu() : State(StateType::PLAY) {}

	template<class Event, class Fsm>
	void on_entry(Event const &, Fsm &) const {
	  std::cout << "StatePlayMenu::on_entry()" << std::endl;
	}

	template<class Event, class Fsm>
	void on_exit(Event const &, Fsm &) const {
	  std::cout << "StatePlayMenu::on_exit()" << std::endl;
	}
      };

    }
  }
}

#endif /* !CPP_RTYPE_STATEPLAYMENU_HPP*/
