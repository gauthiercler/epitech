//
// Created by ventinc on 1/19/18.
//

#include <packet/PlayerIdPacket.hpp>
#include <iostream>
#include <algorithm>
#include <packet/JoinGamePacket.hpp>
#include <packet/LobbyListPacket.hpp>
#include <packet/LobbyEntryPacket.hpp>
#include <packet/CreateLobbyPacket.hpp>
#include <packet/StartGamePacket.hpp>
#include <packet/LobbyJoinPacket.hpp>
#include <packet/Opcodes.hpp>
#include "Engine.hpp"

void rtypeserver::Engine::start(const rnetwork::Endpoint &endpoint) {
	_dlm.loadLibraries("./enemy/lib/");
    initRouter();
    _masterChannel = std::make_shared<rnetwork::ClientMasterChannel>(_ioService, endpoint, rnetwork::Endpoint(endpoint.host(), endpoint.port() + 1));
    _masterChannel->setGateway(std::bind(&rtypeserver::Engine::handlePacket, this, std::placeholders::_1, std::placeholders::_2));
    _masterChannel->setConnectionCallback(std::bind(&rtypeserver::Engine::handleClient, this, std::placeholders::_1));
    _masterChannel->setDisconnectionCallback(std::bind(&rtypeserver::Engine::handleDisconnection, this, std::placeholders::_1));
    _masterChannel->start();
    _ioService.run();
}

void rtypeserver::Engine::handleClient(std::shared_ptr<rnetwork::ClientChannel> channel) {
    auto player = std::make_shared<Player>(std::move(channel), _nextPlayerId++);
    _players.emplace_back(player);
}

void rtypeserver::Engine::handlePacket(std::shared_ptr<rnetwork::ClientChannel> channel, rnetwork::packet::PacketBase &packet) {
    try {
        auto player = getPlayer(channel);
        if (_router.isRegistered(packet.getOp()))
		{
			_router(packet, player);
		}
        else if (player->routerReceiver().isRegistered(packet.getOp()))
        {
            player->routerReceiver()(packet);
        }
        else
            std::clog << "[INFO] Dropped packet: No route found (op: " << packet.getOp() << ")" << std::endl;
    } catch (const std::exception &e) {
        std::clog << "[INFO] Dropped packet: Unable to find related client (op: " << packet.getOp() << ")" << std::endl;
    }
}

void rtypeserver::Engine::initRouter() {
    // Register all routes to handle packets
    _router.registerRoute(rnetwork::packet::op::LobbyListPacket, std::bind(&rtypeserver::Engine::handleLobbyList, this, std::placeholders::_1, std::placeholders::_2));
    _router.registerRoute(rnetwork::packet::op::CreateLobbyPacket, std::bind(&rtypeserver::Engine::handleLobbyCreation, this, std::placeholders::_1, std::placeholders::_2));
    _router.registerRoute(rnetwork::packet::op::LobbyJoinPacket, std::bind(&rtypeserver::Engine::handleJoinLobby, this, std::placeholders::_1, std::placeholders::_2));
    _router.registerRoute(rnetwork::packet::op::LobbyLeavePacket, std::bind(&rtypeserver::Engine::handleLeaveLobby, this, std::placeholders::_1, std::placeholders::_2));
    _router.registerRoute(rnetwork::packet::op::StartGamePacket, std::bind(&rtypeserver::Engine::handleGameStart, this, std::placeholders::_1, std::placeholders::_2));
}

std::shared_ptr<rtypeserver::Player> rtypeserver::Engine::getPlayer(std::shared_ptr<rnetwork::ClientChannel> channel) {
    auto it = std::find_if(_players.begin(), _players.end(), [&](const std::shared_ptr<Player> &player) {
        return player->haveChannel(channel);
    });
    if (it == _players.end())
        throw std::out_of_range("No client matching found");
    else
        return *it;
}

void rtypeserver::Engine::handleLobbyList(rnetwork::packet::PacketBase &packet, std::shared_ptr<rtypeserver::Player> player) {
	std::clog << "[INFO] Listing lobby" << std::endl;
    for (auto &lobby : _games) {
        rnetwork::packet::LobbyEntryPacket entry(lobby.first, lobby.second->nbPlayers());
        player->send(entry);
    }
}

void rtypeserver::Engine::handleLobbyCreation(rnetwork::packet::PacketBase &packet, std::shared_ptr<rtypeserver::Player> player) {
	std::clog << "[INFO] Creating lobby" << std::endl;
    unsigned int gameId = _nextGameId++;
    _games[gameId] = std::make_shared<Game>(gameId, _dlm);
    _games[gameId]->addPlayer(std::move(player));
}

void rtypeserver::Engine::handleJoinLobby(rnetwork::packet::PacketBase &packet, std::shared_ptr<rtypeserver::Player> player) {
    rnetwork::packet::JoinGamePacket joinGamePacket(packet);

	std::clog << "[INFO] Joining lobby : " << joinGamePacket.getId() << std::endl;
    auto game = _games.find(joinGamePacket.getId());
    if (game != _games.end())
        game->second->addPlayer(std::move(player));
    else
        std::clog << "[WARNING] Unable to find game with id " << joinGamePacket.getId() << std::endl;
}

void rtypeserver::Engine::handleGameStart(rnetwork::packet::PacketBase &packet, std::shared_ptr<rtypeserver::Player> player) {
	std::clog << "[INFO] Starting game." << std::endl;
    auto game = player->getGame();
    if (game.get() != nullptr)
    {
        game->start();
        std::thread f([game] {
            game->run();
        });
        f.detach();
    }
}

void rtypeserver::Engine::handleDisconnection(std::shared_ptr<rnetwork::ClientChannel> channel) {
    try {
        auto player = getPlayer(channel);
        auto game = player->getGame();
        std::clog << "[INFO] Player disconnected" << std::endl;
        if (game)
            game->unregisterPlayer(player);
        _players.erase(std::find(_players.begin(), _players.end(), player));
    } catch (const std::exception &e) {
        std::clog << "[WARNING] " << e.what() << std::endl;
    }
}

void rtypeserver::Engine::handleLeaveLobby(rnetwork::packet::PacketBase &packet, std::shared_ptr<rtypeserver::Player> player) {
    std::clog << "[INFO] Player leaving lobby" << std::endl;
    if (player->getGame())
        player->getGame()->unregisterPlayer(player);
}
