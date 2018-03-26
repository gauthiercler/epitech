#ifndef CPP_RTYPE_FSM_HPP
# define CPP_RTYPE_FSM_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_VECTOR_SIZE 50
#define FUSION_MAX_VECTOR_SIZE 50

#include <iostream>
#include "definitions.hpp"

#include "FSM/states/StateMainMenu.hpp"
#include "FSM/states/StateOptionsMenu.hpp"
#include "FSM/states/StateCredits.hpp"
#include "FSM/states/StateExit.hpp"
#include "FSM/states/StatePlayMenu.hpp"
#include "FSM/states/StateSingleplayerMenu.hpp"
#include "FSM/states/StateMultiplayerMenu.hpp"
#include "FSM/states/StateMultiplayerLobbiesListingMenu.hpp"
#include "FSM/states/StateMultiplayerLobbyMenu.hpp"
#include "FSM/states/StateStartGame.hpp"

#include "FSM/events/EventStartComputation.hpp"

#include "FSM/transitions/TransitionSwitchMenuState.hpp"

#include "FSM/guards/GuardTransitionIsTriggered.hpp"

namespace rtype {
  namespace menu {
    namespace FSM {

      struct FSM : public msmf::state_machine_def<FSM> {
	typedef StateMainMenu initial_state;

	StateType requestedState = StateType::NONE;
	StateType activeState = StateType::MAIN_MENU;

	struct transition_table : mpl::vector<
	  msmf::Row <
	  initial_state, EventStartComputation, StateOptionsMenu, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StateOptionsMenu, EventStartComputation, initial_state, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<initial_state, EventStartComputation, StateCredits, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StateCredits, EventStartComputation, initial_state, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<initial_state, EventStartComputation, StateExit, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<initial_state, EventStartComputation, StatePlayMenu, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StatePlayMenu, EventStartComputation, initial_state, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StatePlayMenu, EventStartComputation, StateSingleplayerMenu, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StateSingleplayerMenu, EventStartComputation, StatePlayMenu, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StateSingleplayerMenu, EventStartComputation, StateStartGame, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
		          msmf::Row<StateStartGame, EventStartComputation, StateMultiplayerLobbyMenu, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StatePlayMenu, EventStartComputation, StateMultiplayerMenu, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StateMultiplayerMenu, EventStartComputation, StatePlayMenu, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StateMultiplayerMenu, EventStartComputation, StateMultiplayerLobbiesListingMenu, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StateMultiplayerLobbiesListingMenu, EventStartComputation, StateMultiplayerMenu, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StateMultiplayerLobbiesListingMenu, EventStartComputation, StateMultiplayerLobbyMenu, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StateMultiplayerLobbyMenu, EventStartComputation, StateMultiplayerLobbiesListingMenu, TransitionSwitchMenuState, GuardTransitionIsTriggered>,
				  msmf::Row<StateMultiplayerLobbyMenu, EventStartComputation, StateStartGame, TransitionSwitchMenuState, GuardTransitionIsTriggered>
	> {};

	template<class fsm, class event>
	void no_transition(event const &, fsm &, int state) {
	  std::cout << "no transition for " << state << std::endl;
	}

	template<class FSM, class Event>
	void exception_caught(Event const &, FSM &, std::exception &) {
	  std::cerr << "Error Occurred, Exiting" << std::endl;
	  std::exit(1);
	}

      };

      typedef msm::back::state_machine<FSM> machine;
    }
  }
}


#endif /* !CPP_RTYPE_FSM_HPP*/
