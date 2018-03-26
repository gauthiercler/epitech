#ifndef CPP_RTYPE_CREDITSHANDLER_HPP
# define CPP_RTYPE_CREDITSHANDLER_HPP

#include <imgui.h>
#include "MenuHandler.hpp"
#include "Utils.hpp"

namespace rtype {
  namespace menu {
    namespace GUI {

      class CreditsHandler : public MenuHandler {

      public:

	explicit CreditsHandler(StateType &requestedState) : MenuHandler(requestedState) {}

	virtual ~CreditsHandler() = default;

	void draw() override {
		GUI::createButton("Back", [&](){ _requestedState = StateType::MAIN_MENU; }, {200, 100}, {50, 50});

		auto color = ImVec4(255, 255, 0, 255);

		if (_position <= -ImGui::GetWindowHeight())
			_position = ImGui::GetWindowHeight();


		size_t idx = 0;
		for (auto &contributor : _contributors) {
			auto fontScale = (_position + idx) / 100;
			ImGui::SetWindowFontScale(fontScale);

			ImGui::SetCursorPos(ImVec2(rtype::menu::GUI::getHorizontalTextPosition(contributor), _position + idx));
			ImGui::TextColored(color, "%s", contributor.data());
			idx += 100;
		}
		--_position;
	}

	  private:
		  float _position = 900;
		  std::vector<std::string> _contributors = {
			  "Antoine Foret",
			  "Vincent Dusautoir",
			  "Anthony Leclerc",
			  "Anas Buyumad",
			  "Valentin Montagne",
			  "Gauthier Cler"
		  };
      };
    }
  }
}

#endif /* !CPP_RTYPE_CREDITSHANDLER_HPP*/
