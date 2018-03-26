#ifndef CPP_RTYPE_STATEOPTIONS_HPP
# define CPP_RTYPE_STATEOPTIONS_HPP

#include <iostream>
#include "State.hpp"

namespace rtype {
  namespace menu {
    namespace FSM {

      struct StateOptionsMenu : msmf::state<>, State {

	explicit StateOptionsMenu() : State(StateType::OPTIONS) {}

	template<class Event, class Fsm>
	void on_entry(Event const &, Fsm &) const {
	  std::cout << "StateOptionsMenu::on_entry()" << std::endl;
	}

	template<class Event, class Fsm>
	void on_exit(Event const &, Fsm &) const {
	  std::cout << "StateOptionsMenu::on_exit()" << std::endl;
	}
      };

    }
  }
}

#endif /* !CPP_RTYPE_STATEOPTIONS_HPP*/
