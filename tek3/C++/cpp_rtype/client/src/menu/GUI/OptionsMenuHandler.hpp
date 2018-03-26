#ifndef CPP_RTYPE_OPTIONSMENUHANDLER_HPP
# define CPP_RTYPE_OPTIONSMENUHANDLER_HPP

#include <imgui.h>
#include <array>
#include <unordered_map>
#include <client/include/singleton/Settings.hpp>
#include "MenuHandler.hpp"
#include "Callback.hpp"

namespace rtype {
  namespace menu {
    namespace GUI {

      class OptionsMenuHandler : public MenuHandler {

      public:

	explicit OptionsMenuHandler(StateType &requestedState)
	  : MenuHandler(requestedState) {
		_keys = {
			{"Special", {'K', '\0'}},
			{"Shoot", {'S', 'P', 'A', 'C', 'E', '\0'}},
			{"Left", {'L', 'E', 'F', 'T', '\0'}},
			{"Right", {'R', 'I', 'G', 'H', 'T', '\0'}},
			{"Down", {'D', 'O', 'W', 'N', '\0'}},
			{"Up", {'U', 'P', '\0'}}
		};
	}

	virtual ~OptionsMenuHandler() = default;

	void draw() override {

	  this->drawBackButton();
	  this->drawSliders();
	  this->drawInputConfig();
	}
	  private:

		  void drawBackButton() {
			  GUI::createButton("Back##Return", [&]() { _requestedState = StateType::MAIN_MENU; }, {200, 100}, {50, 50});
			  GUI::createButton("Save",
						  [&]()
						  {
							  auto &settings = Singleton<Settings>::get();
							  settings.setMusicVolume(_musicVolume);
							  settings.setEffectsVolume(_effectsVolume);
							  settings.setKeyboard(new_string<char, 10>(_keys["Up"]),
												   new_string<char, 10>(_keys["Down"]),
												   new_string<char, 10>(_keys["Left"]),
												   new_string<char, 10>(_keys["Right"]),
												   new_string<char, 10>(_keys["Shoot"]),
												   new_string<char, 10>(_keys["Special"])
							  );
						  },
						  {600, 100}, {-1, 750});
	}

	void drawSliders() {
	  ImGui::PushItemWidth(400);
	  ImGui::SetCursorPos(ImVec2(100, 250));
	  ImGui::SliderInt(" Music", &_musicVolume, 0, 100);

	  ImGui::SetCursorPos(ImVec2(100, 500));
	  ImGui::SliderInt(" Effects", &_effectsVolume, 0, 100);
	  ImGui::PopItemWidth();
	}

	void drawInputConfig() {
	  std::pair<int, int> inputCoordinates = {1000, 100};

	  ImGui::PushItemWidth(200);
	  for (auto &_key : _keys) {

	    ImGui::SetCursorPos(
	      ImVec2(inputCoordinates.first, inputCoordinates.second));


	    ImGui::InputText(_key.first.c_str(),
				 _key.second.data(),
				 _key.second.size(),
						 ImGuiInputTextFlags_CharsUppercase);
	    inputCoordinates.second += 100;
	  }

	  ImGui::PopItemWidth();
	}

	  private:
		  int _musicVolume = Singleton<Settings>::get().getMusicVolume();
		  int _effectsVolume = Singleton<Settings>::get().getEffectsVolume();
		  std::unordered_map<std::string, std::array<char, 10>> _keys;
      };

    }
  }
}

#endif /* !CPP_RTYPE_OPTIONSMENUHANDLER_HPP*/
