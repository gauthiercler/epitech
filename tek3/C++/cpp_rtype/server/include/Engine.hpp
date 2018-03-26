//
// Created by ventinc on 1/19/18.
//

#ifndef CPP_RTYPE_ENGINE_HPP
#define CPP_RTYPE_ENGINE_HPP

#include <server/include/libloader/DLLoaderManager.hpp>
#include "ClientMasterChannel.hpp"
#include "Player.hpp"
#include "Game.hpp"

namespace rtypeserver
{

	class Engine
    {

    private:

		unsigned int _nextGameId = 0;
		unsigned int _nextPlayerId = 0;
        rnetwork::async::IOService _ioService;
        std::shared_ptr<rnetwork::ClientMasterChannel> _masterChannel;
        std::deque<std::shared_ptr<Player>> _players;
        std::unordered_map<uint16_t, std::shared_ptr<Game>> _games;
        rnetwork::Router<void(rnetwork::packet::PacketBase&, std::shared_ptr<Player>)> _router;
		rtype::module::DLLoaderManager<void> _dlm;

    public:

        Engine() = default;
        ~Engine() = default;

        void start(const rnetwork::Endpoint &endpoint);

    private:
        void initRouter();
        void handleClient(std::shared_ptr<rnetwork::ClientChannel> channel);
        void handleDisconnection(std::shared_ptr<rnetwork::ClientChannel> channel);
        void handlePacket(std::shared_ptr<rnetwork::ClientChannel> channel, rnetwork::packet::PacketBase &packet);
        std::shared_ptr<Player> getPlayer(std::shared_ptr<rnetwork::ClientChannel> channel);

        void handleLobbyList(rnetwork::packet::PacketBase &packet, std::shared_ptr<Player> player);
        void handleLobbyCreation(rnetwork::packet::PacketBase &packet, std::shared_ptr<Player> player);
        void handleJoinLobby(rnetwork::packet::PacketBase &packet, std::shared_ptr<Player> player);
        void handleLeaveLobby(rnetwork::packet::PacketBase &packet, std::shared_ptr<Player> player);
        void handleGameStart(rnetwork::packet::PacketBase &packet, std::shared_ptr<Player> player);
    };
}

#endif //CPP_RTYPE_ENGINE_HPP
