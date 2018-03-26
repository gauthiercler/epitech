#ifndef CPP_RTYPE_STATEEXIT_HPP
# define CPP_RTYPE_STATEEXIT_HPP

#include <iostream>
#include "State.hpp"

namespace rtype {
  namespace menu {
    namespace FSM {

      struct StateExit : msmf::state<>, State {

	explicit StateExit() : State(StateType::EXIT) {}

	template<class Event, class Fsm>
	void on_entry(Event const &, Fsm &fsm) const {
	  fsm.activeState = this->getType();
	  std::cout << "StateExit::on_entry()" << std::endl;
	}

	template<class Event, class Fsm>
	void on_exit(Event const &, Fsm &) const {
	  std::cout << "StateExit::on_exit()" << std::endl;
	}
      };
    }
  }
}

#endif /* !CPP_RTYPE_STATEEXIT_HPP*/
