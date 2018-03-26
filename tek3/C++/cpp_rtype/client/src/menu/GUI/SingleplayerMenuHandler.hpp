#ifndef CPP_RTYPE_SINGLEPLAYERMENUHANDLER_HPP
# define CPP_RTYPE_SINGLEPLAYERMENUHANDLER_HPP

#include <imgui.h>
#include "MenuHandler.hpp"

namespace rtype {
  namespace menu {
    namespace GUI {
		class SinglePlayerMenuHandler : public MenuHandler {

		public:
			explicit SinglePlayerMenuHandler(StateType &requestedState)
				: MenuHandler(requestedState) {}

			virtual ~SinglePlayerMenuHandler() = default;

			void draw() override {
				GUI::createButton("Back", [&](){ _requestedState = StateType::PLAY; }, {200, 100}, {50, 50});

				ImGui::SetCursorPos(ImVec2(500, 500));
				if (ImGui::Button("Start")) {
//					_requestedState = StateType::START;
				}
			}
	  };
    }
  }
}

#endif /* !CPP_RTYPE_SINGLEPLAYERMENUHANDLER_HPP*/
