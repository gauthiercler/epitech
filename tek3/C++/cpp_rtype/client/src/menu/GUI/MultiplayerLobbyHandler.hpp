#ifndef CPP_RTYPE_MULTIPLAYERLOBBYHANDLER_HPP
# define CPP_RTYPE_MULTIPLAYERLOBBYHANDLER_HPP

#include <imgui.h>
#include <packet/StartGamePacket.hpp>
#include <packet/Opcodes.hpp>
#include <packet/LobbyLeavePacket.hpp>
#include <packet/PlayerLeavedPacket.hpp>
#include <packet/PlayerJoinedPacket.hpp>
#include "MenuHandler.hpp"

namespace rtype {
  namespace menu {
    namespace GUI {

      class MultiplayerLobbyHandler : public MenuHandler {

	  public:

		  explicit MultiplayerLobbyHandler(StateType &requestedState)
			  : MenuHandler(requestedState)
		  {
			  auto &router = Singleton<NetworkManager>::get().getRouter();

			  router.registerRoute(rnetwork::packet::op::StartGamePacket,
			  [&](rnetwork::packet::PacketBase &packet)
			  {
				  Context::get().state = ContextState::GAME;
			  });

			  router.registerRoute(rnetwork::packet::op::LobbyLeavePacket,
			  [&](rnetwork::packet::PacketBase &packet)
			  {
				 _requestedState = StateType::MULTIPLAYER_LOBBIES_LIST;
			  });

			  router.registerRoute(rnetwork::packet::op::PlayerJoinedPacket,
				[&](rnetwork::packet::PacketBase &packet)
				{
					rnetwork::packet::PlayerJoinedPacket entry;

					std::cout << "Player joined with id : " << entry.getId() << std::endl;
					_players.push_back(entry);

				});

			  router.registerRoute(rnetwork::packet::op::PlayerLeavedPacket,
				[&](rnetwork::packet::PacketBase &packet)
				{
					rnetwork::packet::PlayerLeavedPacket entry;

					auto it = std::find_if(_players.begin(), _players.end(),
					[&entry](const rnetwork::packet::PlayerJoinedPacket &current)
					{
						return current.getId() == entry.getId();
					});
					if (it != _players.end())
						_players.erase(it);
				});
		  }

		  virtual ~MultiplayerLobbyHandler() = default;

		  void renderEnemies() {

			  ImGui::SetCursorPos(ImVec2(ImGui::GetWindowWidth() - 400, 200));
			  ImGui::Text("%s", "Enemies");
			  int yIndex = 275;
			  for (auto &&enemy : _enemies) {
				  ImGui::SetCursorPos(ImVec2(ImGui::GetWindowWidth() - 500, yIndex));
				  ImGui::Checkbox(enemy.name.c_str(), &enemy.enabled);
				  yIndex += 75;
			  }
		  }

		  void renderPlayers() {
			  ImGui::SetCursorPos({175, 775});
			  ImGui::Text("%lu / %d", _players.size(), 4);

			  float yIndex = 250;
			  for (auto &player : _players) {
				  ImGui::SetCursorPos({100, yIndex});
				  ImGui::Text("Player #%d", player.getId());
			  }
		  }

		  void draw() override {
			  GUI::createButton("Back",
								[&]()
								{
									rnetwork::packet::LobbyLeavePacket packet;
									Singleton<NetworkManager>::get().getClientChannel()->tcpSend(packet);
								}, {200, 100}, {50, 50});

			  this->renderPlayers();
			  this->renderEnemies();

			  GUI::createButton("Start", [&]()
			  {
				  Singleton<NetworkManager>::get().getClientChannel()->tcpSend(rnetwork::packet::StartGamePacket());

			  },{600, 100}, {-1, ImGui::GetWindowHeight() - 150});
		  }

	  private:

		  struct Enemy {
			  std::string name;
			  bool enabled;
		  };

		  struct Player {
			  size_t id;
		  };

		  std::vector<Enemy> _enemies = {
			  {"Basic", true},
			  {"Intermediate", false},
			  {"Advanced", false}
		  };

		  std::vector<rnetwork::packet::PlayerJoinedPacket> _players;

	  };

    }
  }
}

#endif /* !CPP_RTYPE_MULTIPLAYERLOBBYHANDLER_HPP*/
