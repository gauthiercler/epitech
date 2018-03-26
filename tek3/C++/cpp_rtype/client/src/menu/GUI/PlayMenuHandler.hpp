#ifndef CPP_RTYPE_PLAYMENUHANDLER_HPP
# define CPP_RTYPE_PLAYMENUHANDLER_HPP

#include <imgui.h>
#include "MenuHandler.hpp"
#include "Utils.hpp"

namespace rtype {
  namespace menu {
    namespace GUI {

      class PlayMenuHandler : public MenuHandler {

      public:

	explicit PlayMenuHandler(StateType &requestedState) : MenuHandler(
	  requestedState) {}

	virtual ~PlayMenuHandler() = default;

	void draw() override {
		GUI::createButton("Back", [&](){ _requestedState = StateType::MAIN_MENU; }, {200, 100}, {50, 50});
		GUI::createButton("Singleplayer",
						  [&]()
						  {
//							  _requestedState = StateType::SINGLEPLAYER;
						  }, {450, 100}, {-1, 250});
		GUI::createButton("Multiplayer", [&](){ _requestedState = StateType::MULTIPLAYER; }, {450, 100}, {-1, 450});
	}
      };

    }
  }
}

#endif /* !CPP_RTYPE_PLAYMENUHANDLER_HPP*/
