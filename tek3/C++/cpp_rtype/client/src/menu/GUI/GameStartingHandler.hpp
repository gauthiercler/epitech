#ifndef CPP_RTYPE_GAMESTARTINGHANDLER_HPP
# define CPP_RTYPE_GAMESTARTINGHANDLER_HPP

#include <client/ImGui/imgui.h>
#include "MenuHandler.hpp"

namespace rtype {
	namespace menu {
		namespace GUI {

			class GameStartingHandler : public MenuHandler {

			public:

				explicit GameStartingHandler(StateType &requestedState) : MenuHandler(
					requestedState) {}

				virtual ~GameStartingHandler() = default;

				void draw() override {
					ImGui::SetCursorPos(ImVec2(500, 250));
					ImGui::TextColored(ImVec4(255, 255, 0, 255), "Starting Game");
				}

			};
		}
	}
}

#endif /* !CPP_RTYPE_GAMESTARTINGHANDLER_HPP*/
