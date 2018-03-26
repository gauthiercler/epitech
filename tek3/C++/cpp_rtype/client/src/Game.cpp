//
// Created by ventinc on 1/10/18.
//

#include <chrono>
#include <system/FontDrawable.hpp>
#include <system/FPSCalculator.hpp>
#include <client/include/system/HandleShoot.hpp>
#include <Acceleration.hpp>
#include <client/include/system/AddAcceleration.hpp>
#include <BoundingBox.hpp>
#include <Collide.hpp>
#include <rnetwork/udp/Client.hpp>
#include <Dead.hpp>
#include <client/include/system/Collisions.hpp>
#include <client/include/system/Death.hpp>
#include <client/include/system/Starfield.hpp>
#include <Star.hpp>
#include <client/include/singleton/Window.hpp>
#include <client/include/singleton/NetworkManager.hpp>
#include <client/include/system/SendToNetwork.hpp>
#include <packet/StartGamePacket.hpp>
#include <Weapon.hpp>
#include <client/include/system/RemoveWhenOutBounds.hpp>
#include <client/include/spawner/SimpleBullet.hpp>
#include <client/include/singleton/Settings.hpp>
#include <packet/EntitySpawnPacket.hpp>
#include <client/include/singleton/ServerId.hpp>
#include <packet/MovePacket.hpp>
#include <client/include/system/UpdateNetworkMove.hpp>
#include <shared/EntityType.hpp>
#include "asset/Font.hpp"
#include "components/RtypeInput.hpp"
#include "system/HandleInput.hpp"
#include "components/FPS.hpp"
#include "components/Drawable.hpp"
#include "components/Text.hpp"
#include "components/RtypeCommand.hpp"
#include "system/EntityDrawable.hpp"
#include "system/HandleMoveInput.hpp"
#include "system/Render.hpp"
#include "system/Move.hpp"
#include "system/RemoveWhenOutBounds.hpp"
#include "Square.hpp"
#include "Game.hpp"
#include "packet/Opcodes.hpp"

rtype::Game::Game(sf::RenderWindow &window)
	: AContext(window), _assetsLoader(Singleton<AssetsLoader>::get()) {
  	try {
		this->initComponentStores();
  	} catch (std::exception &e) {
		std::cerr << "Error during the initialization of the components stores : " << e.what() << std::endl;
  	}
  	try {
		this->initSystems();
  	} catch (std::exception &e) {
    	std::cerr << "Error during the initialization of the systems : " << e.what() << std::endl;
  	}
	try {
		this->initAssets();
  	} catch (std::exception &e) {
    	std::cerr << "Error during the initialization of the assets : " << e.what() << std::endl;
  	}

	namespace Opcode = rnetwork::packet::op;
	using Packet = rnetwork::packet::PacketBase;

	auto& net = Singleton<NetworkManager>::get();
	auto& serverIds = Singleton<ServerId>::get();

	net.getRouter().registerRoute(Opcode::EntitySpawn, [&](Packet& p) {
		rnetwork::packet::EntitySpawnPacket ep(p);

		std::cout << "[RECEIVED] => SPAWN." << std::endl;
		auto eid = this->spawnPlayer(static_cast<EntityType>(ep.getType()), ep.getpos());
		serverIds.associateId(ep.getId(), eid);
	});

	net.getRouter().registerRoute(Opcode::MovePacket, [&](Packet& p) {
		rnetwork::packet::MovePacket mp(p);

		auto pos = mp.getPosition();
		std::clog << "[Move received] ID :: " << mp.getPlayerId() << " At: " << pos.x << ", " << pos.y << std::endl;

		_movepackets.push(mp);
	});

	_window.setFramerateLimit(60);
}

void rtype::Game::initAssets() {
	_assetsLoader.createAssetsStore<asset::Font>();
	_assetsLoader.load<asset::Font>(0, "./client/assets/font.ttf");
}

void rtype::Game::initComponentStores() {
	_manager.createComponentStore<ct::Position>();
	_manager.createComponentStore<ct::Speed>();
	_manager.createComponentStore<ct::PlayerID>();
	_manager.createComponentStore<ct::RtypeCommand>();
	_manager.createComponentStore<ct::RtypeInput>();
	_manager.createComponentStore<ct::Star>();
	_manager.createComponentStore<ct::Drawable>();
	_manager.createComponentStore<sf::Color>();
	_manager.createComponentStore<ct::Text>();
	_manager.createComponentStore<ct::FPS>();
	_manager.createComponentStore<ct::Weapon>();
	_manager.createComponentStore<ct::Acceleration>();
	_manager.createComponentStore<ct::BoundingBox>();
	_manager.createComponentStore<ct::Collide>();
	_manager.createComponentStore<ct::Dead>();
}

void rtype::Game::initSystems() {

	_manager.addSystem(std::make_shared<UpdateNetworkMove>(_movepackets));
	_manager.addSystem(std::make_shared<Starfield>());
	_manager.addSystem(std::make_shared<HandleInput>(_window));
	_manager.addSystem(std::make_shared<HandleMoveInput>(_window));
	_manager.addSystem(std::make_shared<HandleShoot>());
	_manager.addSystem(std::make_shared<AddAcceleration>());
	_manager.addSystem(std::make_shared<Move>());
	_manager.addSystem(std::make_shared<Collisions>());

	_manager.addSystem(std::make_shared<SendToNetwork>(Singleton<NetworkManager>::get().getClientChannel()));
	ct::BoundingBox worldbox { _window.getSize().x, _window.getSize().y };

	_manager.addSystem(std::make_shared<RemoveWhenOutBounds>(worldbox));
	_manager.addSystem(std::make_shared<Death>());
	_manager.addSystem(std::make_shared<FPSCalculator>());
	_manager.addSystem(std::make_shared<EntityDrawable>());
	_manager.addSystem(std::make_shared<FontDrawable>(_assetsLoader));
	_manager.addSystem(std::make_shared<Render>(_window));
}

void rtype::Game::initFPS() {
	auto entity = _manager.createEntity();

	ct::Text text;
	text.color = sf::Color(0, 255, 255);
	_manager.addComponent(entity, ct::Position(WWIDTH - 50, 0));
	_manager.addComponent(entity, ct::FPS());
	_manager.addComponent(entity, std::move(text));
	_manager.registerEntity(entity);
}

void rtype::Game::run(sf::Time &time) {
	if (!this->_isInit) {
		this->init();
		this->_isInit = true;
	}
	_manager.processSystems(time.asSeconds());
	if (this->_manager.isEnded()) {
		this->_manager.reset();
		Singleton<Context>::get().state = ContextState::MENU;
		this->_isInit = false;
	}
}

void rtype::Game::init() {

	this->initFPS();
}

ecs::Entity rtype::Game::spawnPlayer(rtype::EntityType type, rtype::ct::Position const& pos)
{
	auto e = _manager.createEntity();

	std::cout << "Spawn at pos : " << pos.x << ", " << pos.y << std::endl;

	if (type == EntityType::OURPLAYER)
	{
		_manager.addComponent(e, ct::RtypeInput(Singleton<Settings>::get().getKeyboard()));
		_manager.addComponent(e, ct::RtypeCommand());
	}

	_manager.addComponent(e, pos);
	 _manager.addComponent(e, ct::Speed(0, 0));
	_manager.addComponent(e, ct::BoundingBox(80, 40));
	_manager.addComponent(e, sf::Color(255, 255, 255));
	_manager.addComponent(e, ct::Weapon(std::make_unique<spawner::SimpleBullet>()));
	 _manager.addComponent(e, ct::Collide(ct::Collide::CollideType::PLAYER));
	_manager.addComponent(e, ct::Drawable(ct::Drawable()));
	ct::PlayerID _id;
	_id.id = type == EntityType::OURPLAYER ? rtype::ct::PlayerID::BLUE : rtype::ct::PlayerID::RED;
	_manager.addComponent(e, _id);

	_manager.registerEntity(e);
	return e;
}
