//
// Created by ventinc on 1/19/18.
//

#include <server/include/system/Move.hpp>
#include <packet/LobbyJoinPacket.hpp>
#include <packet/StartGamePacket.hpp>
#include <packet/MovePacket.hpp>
#include <packet/Opcodes.hpp>
#include <packet/EntitySpawnPacket.hpp>
#include "system/NotifyMove.hpp"
#include "system/UpdateMove.hpp"
#include <Library.hpp>
#include <packet/PlayerLeavedPacket.hpp>
#include <packet/PlayerJoinedPacket.hpp>
#include "Life.hpp"
#include "LifeTime.hpp"
#include "Acceleration.hpp"
#include "BoundingBox.hpp"
#include "Collide.hpp"
#include "Dead.hpp"
#include "Game.hpp"

rtypeserver::Game::Game(unsigned int id, rtype::module::DLLoaderManager<void> &dlm)
	: _id(id), _running(false), _spawnerManager(_manager)
{
    this->last = std::chrono::high_resolution_clock::now();
	dlm.fillSpawnerManager(_spawnerManager);
}

void rtypeserver::Game::initComponentsStore() {
    this->_manager.createComponentStore<rtype::ct::Position>();
    this->_manager.createComponentStore<rtype::ct::Speed>();
    this->_manager.createComponentStore<rtype::ct::Acceleration>();
    this->_manager.createComponentStore<rtype::ct::BoundingBox>();
    this->_manager.createComponentStore<rtype::ct::Collide>();
	this->_manager.createComponentStore<rtype::ct::Dead>();
	this->_manager.createComponentStore<rtype::ct::Life>();
	this->_manager.createComponentStore<rtype::ct::LifeTime>();
	this->_manager.createComponentStore<rtype::ct::Library>();
}

void rtypeserver::Game::initSystems() {
	this->_manager.addSystem(std::make_shared<UpdateMove>(_moveUpdates));
    this->_manager.addSystem(std::make_shared<Move>());
	this->_manager.addSystem(std::make_shared<NotifyMove>(_players));
}

void rtypeserver::Game::run() {
	while (_running)
	{
		auto now = std::chrono::high_resolution_clock::now();
		float elapsed = std::chrono::duration<float>(now - last).count();
		callSpawners(elapsed);
		this->_manager.processSystems(elapsed);
		this->last = now;
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

bool rtypeserver::Game::addPlayer(std::shared_ptr<rtypeserver::Player> player) {
    rnetwork::packet::PlayerJoinedPacket packet(player->getId());
    if (nbPlayers() >= 4) {
        std::clog << "[INFO] Refused client on game " << _id << " cause it contain already " << nbPlayers() << std::endl;
        return false;
    }
    player->joinGame(shared_from_this());
    for (const auto &ally : _players) {
        packet.setId(ally->getId());
        player->send(packet);
    }
	_players.emplace_back(player);
    if (_running)
        startPlayer(player);
    return true;
}

unsigned long rtypeserver::Game::nbPlayers() const {
    return _players.size();
}

unsigned int rtypeserver::Game::getId() const {
    return _id;
}

void rtypeserver::Game::unregisterPlayer(std::shared_ptr<rtypeserver::Player> player) {
    auto end = std::remove_if(_players.begin(), _players.end(), [&](const std::shared_ptr<Player> &_player) {
        return player == _player;
    });
    rnetwork::packet::PlayerLeavedPacket packet(player->getId());
    // TODO Remove entity from this particular client
    player->leaveGame();
    broadcast(packet);
    _players.erase(end, _players.end());
}

void rtypeserver::Game::start() {
    if (_running)
        return;
    _running = true;
	initComponentsStore();
	initSystems();
    for (auto &player : _players) {
        startPlayer(player);
    }
}

void rtypeserver::Game::startPlayer(std::shared_ptr<rtypeserver::Player> player) {
    rnetwork::packet::StartGamePacket packet;
    player->routerReceiver().registerRoute(
        rnetwork::packet::op::MovePacket,
        [&] (rnetwork::packet::PacketBase const& _packet) {
            rnetwork::packet::MovePacket move(_packet);
			_moveUpdates.push(move);
        });
    player->send(packet);

	auto eid = makePlayer();
	if (eid != ecs::InvalidEntity)
	{
		for (auto&& p : _players)
		{
			if (p->getId() == player->getId())
			{
				rnetwork::packet::EntitySpawnPacket sp(static_cast<uint32_t>(eid), static_cast<uint16_t>(rtype::EntityType::OURPLAYER), rtype::ct::Position());
				p->send(sp);
			}
			else
			{
				rnetwork::packet::EntitySpawnPacket sp(static_cast<uint32_t>(eid), static_cast<uint16_t>(rtype::EntityType::PLAYER), rtype::ct::Position());
				p->send(sp);
			}
		}
	}

}

ecs::Entity rtypeserver::Game::makePlayer()
{
	auto eid = _manager.createEntity();
	if (eid == ecs::InvalidEntity)
		return eid;
	_manager.addComponent(eid, rtype::ct::Position());
	_manager.addComponent(eid, rtype::ct::Speed(0, 0));

	_manager.registerEntity(eid);
	return eid;
}

void rtypeserver::Game::broadcast(rnetwork::packet::PacketBase& p) {
	for (auto &&pl : _players) {
		pl->send(p);
	}
}

void rtypeserver::Game::callSpawners(float elapsedTime) {
	//std::cout << "Elapsed time : " << elapsedTime << std::endl;
	//std::cout << "Entities : " << _manager.getEntities().size() << std::endl;
	_spawnerManager.updateSpawners(elapsedTime);
}