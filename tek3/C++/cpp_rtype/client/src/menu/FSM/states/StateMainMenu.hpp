#ifndef CPP_RTYPE_STATEMENU_HPP
# define CPP_RTYPE_STATEMENU_HPP

#include <iostream>
#include "State.hpp"

namespace rtype {
  namespace menu {
    namespace FSM {

      struct StateMainMenu : msmf::state<>, State {

	explicit StateMainMenu() : State(StateType::MAIN_MENU) {}

	template<class Event, class Fsm>
	void on_entry(Event const &, Fsm &) const {
	  std::cout << "StateMainMenu::on_entry()" << std::endl;
	}

	template<class Event, class Fsm>
	void on_exit(Event const &, Fsm &) const {
	  std::cout << "StateMainMenu::on_exit()" << std::endl;
	}
      };
    }
  }
}


#endif /* !CPP_RTYPE_STATEMENU_HPP*/
