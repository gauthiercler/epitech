#ifndef CPP_RTYPE_MULTIPLAYERMENUHANDLER_HPP
# define CPP_RTYPE_MULTIPLAYERMENUHANDLER_HPP

#include <imgui.h>
#include <client/include/singleton/NetworkManager.hpp>
#include <rnetwork/exceptions/ConnectionError.hpp>
#include "MenuHandler.hpp"

namespace rtype {
  namespace menu {
    namespace GUI {
		class MultiplayerMenuHandler : public MenuHandler {
		public:
			explicit MultiplayerMenuHandler(StateType &requestedState) : MenuHandler(requestedState) {
				
			}

			virtual ~MultiplayerMenuHandler() = default;

			void draw() override {
				GUI::createButton("Back", [&](){ _requestedState = StateType::PLAY; }, {200, 100}, {50, 50});

				ImGui::SetCursorPos({GUI::getHorizontalTextPosition("IP address:"), 100});
				ImGui::Text("%s", "IP address:");

				ImGui::SetCursorPos({GUI::getHorizontalTextPosition("Port:"), 350});
				ImGui::Text("%s", "Port:");

				ImGui::PushItemWidth(500);
				ImGui::SetCursorPos(ImVec2(550, 200));
				ImGui::InputText("##IP", _ip.data(), _ip.size());

				ImGui::PushItemWidth(300);
				ImGui::SetCursorPos(ImVec2(650, 450));
				ImGui::InputInt("##Port", &_port);

				ImGui::PopItemWidth();

				ImGui::SetCursorPos({GUI::getHorizontalTextPosition(_error), 750});
				ImGui::TextColored(ImVec4(255, 0, 0, 255), "%s", _error.c_str());

				GUI::createButton("Connect",
								  [&]()
								  {
									  _error = "";
									  auto& networkManager = Singleton<NetworkManager>::get();
									  auto clientChannel = networkManager.getClientChannel();

									  try {
										  clientChannel->handshake(rnetwork::Endpoint(new_string<char, 100>(_ip),
																					  static_cast<uint16_t>(_port)));
										  _requestedState = StateType::MULTIPLAYER_LOBBIES_LIST;
									  } catch (rnetwork::exceptions::ConnectionError &e) {
										  _error = e.what();
									  }
								  }, {300, 100}, {-1, 600});
			}

		private:
			int _port = 4242;
			std::array<char, 100> _ip{{'1','2','7','.','0','.','0','.','1', '\0'}};
			std::string _error;
		};
	}
  }
}

#endif /* !CPP_RTYPE_MULTIPLAYERMENUHANDLER_HPP*/
