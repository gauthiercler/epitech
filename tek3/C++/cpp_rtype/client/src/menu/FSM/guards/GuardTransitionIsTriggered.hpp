#ifndef CPP_RTYPE_GUARDTRANSITIONISTRIGGERED_HPP
# define CPP_RTYPE_GUARDTRANSITIONISTRIGGERED_HPP

#include <iostream>


namespace rtype {
  namespace menu {
    namespace FSM {

      struct GuardTransitionIsTriggered {
	template<class Fsm, class Evt, class SourceState, class TargetState>
	bool
	operator()(Evt const &, Fsm &fsm, SourceState &, TargetState &target) {
	  return fsm.requestedState == target.getType();
	}
      };
    }
  }
}


#endif /* !CPP_RTYPE_GUARDISTRANSITIONTRIGGERED_HPP*/
