//
// Created by rubysh on 11/01/18.
//

#ifndef CPP_RTYPE_STATESTARTGAME_HPP
#define CPP_RTYPE_STATESTARTGAME_HPP

#include <iostream>
#include "State.hpp"

namespace rtype {
  namespace menu {
    namespace FSM {

      struct StateStartGame : msmf::state<>, State {

	explicit StateStartGame() : State(StateType::START) {}

	template<class Event, class Fsm>
	void on_entry(Event const &, Fsm &fsm) const {
//		Context::get().state = ContextState::GAME;
//		fsm.requestedState = StateType::MULTIPLAYER_LOBBIES_LIST;
		std::cout << "StateStartGame::on_entry()" << std::endl;
	}

	template<class Event, class Fsm>
	void on_exit(Event const &, Fsm &) const {
	  std::cout << "StateStartGame::on_exit()" << std::endl;
	}
      };

    }
  }
}

#endif //CPP_RTYPE_STATESTARTGAME_HPP
