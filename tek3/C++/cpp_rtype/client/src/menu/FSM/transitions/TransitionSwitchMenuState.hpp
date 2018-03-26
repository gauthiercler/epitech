//
// Created by rubysh on 11/01/18.
//

#ifndef CPP_RTYPE_TRANSITIONSWITCHMENUSTATE_HPP
#define CPP_RTYPE_TRANSITIONSWITCHMENUSTATE_HPP

namespace rtype {
  namespace menu {
    namespace FSM {

      struct TransitionSwitchMenuState {

	template<class Event, class Fsm, class SourceState, class TargetState>
	void operator()(Event const &, Fsm &fsm, SourceState &,
			TargetState &targetState) {
	  fsm.requestedState = StateType::NONE;
	  fsm.activeState = targetState.getType();
	}
      };
    }
  }
}


#endif //CPP_RTYPE_TRANSITIONSWITCHMENUSTATE_HPP
