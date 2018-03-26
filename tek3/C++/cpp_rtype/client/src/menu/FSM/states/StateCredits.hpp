#ifndef CPP_RTYPE_STATECREDITS_HPP
# define CPP_RTYPE_STATECREDITS_HPP

#include <iostream>
#include "State.hpp"

namespace rtype {
  namespace menu {
    namespace FSM {

      struct StateCredits : msmf::state<>, State {

	explicit StateCredits() : State(StateType::CREDITS) {}

	template<class Event, class Fsm>
	void on_entry(Event const &, Fsm &) const {
	  std::cout << "StateCredits::on_entry()" << std::endl;
	}

	template<class Event, class Fsm>
	void on_exit(Event const &, Fsm &) const {
	  std::cout << "StateCredits::on_exit()" << std::endl;
	}
      };
    }
  }
}

#endif /* !CPP_RTYPE_STATECREDITS_HPP*/
