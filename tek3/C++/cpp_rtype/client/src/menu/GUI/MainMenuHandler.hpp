#ifndef CPP_RTYPE_MAINMENUHANDLER_HPP
# define CPP_RTYPE_MAINMENUHANDLER_HPP

#include <imgui.h>
#include "MenuHandler.hpp"

namespace rtype {
  namespace menu {
    namespace GUI {

      class MainMenuHandler : public MenuHandler {

      public:

	explicit MainMenuHandler(StateType &requestedState) : MenuHandler(
	  requestedState) {}

	virtual ~MainMenuHandler() = default;

	void draw() override {

		GUI::createButton("Play", [&](){ _requestedState = StateType::PLAY; }, {600, 100}, {-1, 200});
		GUI::createButton("Options", [&](){ _requestedState = StateType::OPTIONS; }, {600, 100}, {-1, 350});
		GUI::createButton("Credits", [&](){ _requestedState = StateType::CREDITS; }, {600, 100}, {-1, 500});
		GUI::createButton("Exit", [&](){ _requestedState = StateType::EXIT; }, {600, 100}, {-1, 650}); }
      };

    }
  }
}

#endif /* !CPP_RTYPE_MAINMENUHANDLER_HPP*/
