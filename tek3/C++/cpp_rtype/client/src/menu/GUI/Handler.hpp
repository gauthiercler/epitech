#ifndef CPP_RTYPE_HANDLER_HPP
# define CPP_RTYPE_HANDLER_HPP

#include <memory>
#include <functional>
#include <unordered_map>
#include "State.hpp"
#include "CreditsHandler.hpp"
#include "MainMenuHandler.hpp"
#include "OptionsMenuHandler.hpp"
#include "ExitHandler.hpp"
#include "PlayMenuHandler.hpp"
#include "SingleplayerMenuHandler.hpp"
#include "MultiplayerMenuHandler.hpp"
#include "MultiplayerLobbyHandler.hpp"
#include "MultiplayerLobbiesListingHandler.hpp"
#include "GameStartingHandler.hpp"

namespace rtype {
  namespace menu {
    namespace GUI {
      class Handler {

      public:

	explicit Handler(StateType &requestedState) {
		_stateActions[StateType::MAIN_MENU] = std::make_unique<MainMenuHandler>(requestedState);
		_stateActions[StateType::OPTIONS] = std::make_unique<OptionsMenuHandler>(requestedState);
		_stateActions[StateType::CREDITS] = std::make_unique<CreditsHandler>(requestedState);
		_stateActions[StateType::EXIT] = std::make_unique<ExitHandler>(requestedState);
		_stateActions[StateType::PLAY] = std::make_unique<PlayMenuHandler>(requestedState);
		_stateActions[StateType::SINGLEPLAYER] = std::make_unique<SinglePlayerMenuHandler>(requestedState);
		_stateActions[StateType::MULTIPLAYER] = std::make_unique<MultiplayerMenuHandler>(requestedState);
		_stateActions[StateType::MULTIPLAYER_LOBBIES_LIST] = std::make_unique<MultiplayerLobbiesListingHandler>(requestedState);
		_stateActions[StateType::MULTIPLAYER_LOBBY] = std::make_unique<MultiplayerLobbyHandler>(requestedState);
		_stateActions[StateType::START] = std::make_unique<GameStartingHandler>(requestedState);
	};

	MenuHandler &getStateHandler(StateType state) {
	  return *_stateActions.at(state);
	}

      private:
	std::unordered_map<StateType, std::unique_ptr<rtype::menu::GUI::MenuHandler>, util::EnumClassHash> _stateActions;
      };
    }
  }
}

#endif /* !CPP_RTYPE_HANDLER_HPP*/
