#ifndef CPP_RTYPE_MULTIPLAYERLOBBIESLISTINGHANDLER_HPP
# define CPP_RTYPE_MULTIPLAYERLOBBIESLISTINGHANDLER_HPP

#include <imgui.h>
#include <packet/LobbyListPacket.hpp>
#include <packet/CreateLobbyPacket.hpp>
#include <packet/LobbyJoinPacket.hpp>
#include <packet/LobbyEntryPacket.hpp>
#include <packet/Opcodes.hpp>
#include "MenuHandler.hpp"

namespace rtype {
  namespace menu {
    namespace GUI {

      class MultiplayerLobbiesListingHandler : public MenuHandler {

      public:

	explicit MultiplayerLobbiesListingHandler(StateType &requestedState)
	  : MenuHandler(requestedState) {

		auto &router = Singleton<NetworkManager>::get().getRouter();

		router.registerRoute(rnetwork::packet::op::LobbyJoinPacket,
							 [&](rnetwork::packet::PacketBase &packet)
							 {
								 std::cout << "join" << std::endl;
								 _requestedState = StateType::MULTIPLAYER_LOBBY;
							 });

		router.registerRoute(rnetwork::packet::op::LobbyEntryPacket,
		[&](rnetwork::packet::PacketBase &packet)
		{
			rnetwork::packet::LobbyEntryPacket entry(packet);
			_lobbies.push_back(entry);
			_lobbiesRepresentations.push_back("Lobby #" + std::to_string(entry.getId()) + " (" + std::to_string(entry.getPlayersNb()) + " players)");
		});

	}

	virtual ~MultiplayerLobbiesListingHandler() = default;


	void draw() override {
		GUI::createButton("Back", [&](){ _requestedState = StateType::MULTIPLAYER; }, {200, 100}, {50, 50});

		ImGui::SetCursorPos(ImVec2(GUI::getHorizontalTextPosition("List of available games:"), 100));

		ImGui::TextColored(ImVec4(255, 255, 0, 255), "%s", "List of available games:");

		ImGui::SetCursorPos(ImVec2(300, 200));
		ImGui::PushItemWidth(1000);
		GUI::createListBox("", &_selectedItem, _lobbiesRepresentations);
		ImGui::PopItemWidth();

		auto networkManager = Singleton<NetworkManager>::get();
		auto clientChannel = networkManager.getClientChannel();

		GUI::createButton("Reload",
						  [&]()
						  {
							  _selectedItem = -1;
							  _lobbies.clear();
							  _lobbies.erase(_lobbies.begin(), _lobbies.end());
							  _lobbiesRepresentations.clear();
							  _lobbiesRepresentations.erase(_lobbiesRepresentations.begin(), _lobbiesRepresentations.end());
							  rnetwork::packet::LobbyListPacket packet;
							  clientChannel->tcpSend(packet);
						  }, {250, 100}, {-1, 750});

		if (_selectedItem != -1)
			GUI::createButton("Connect", [&]()
			{
				rnetwork::packet::LobbyJoinPacket packet;

				packet.setId(_lobbies.at(static_cast<unsigned long>(_selectedItem)).getId());
				Singleton<NetworkManager>::get().getClientChannel()->tcpSend(packet);

			}, {490, 100}, {300, 600});

		GUI::createButton("Create",
						  [&]()
						  {
							  rnetwork::packet::CreateLobbyPacket packet;
							  std::cout << "Creating lobby" << std::endl;
							  clientChannel->tcpSend(packet);

						  }, {490, 100}, {810, 600});
	}

	  private:
		  int _selectedItem = -1;
		std::vector<rnetwork::packet::LobbyEntryPacket> _lobbies;
		std::vector<std::string> _lobbiesRepresentations;
      };

    }
  }
}

#endif /* !CPP_RTYPE_MULTIPLAYERLOBBIESLISTINGHANDLER_HPP*/
