//
// Created by ventinc on 1/19/18.
//

#include "Position.hpp"
#include "server/include/spawner/PlayerSpawner.hpp"
#include "server/include/spawner/Spawner.hpp"
/*
rtypeserver::spawner::Spawner::Spawner() {
	this->funcTab = {
		{rtype::EntityType::PLAYER, std::bind(&Spawner::spawnPlayer, this, std::placeholders::_1)}
	};
}

ecs::Entity rtypeserver::spawner::Spawner::spawn(ecs::Manager &manager, rtype::EntityType type) {
	auto spawner = this->funcTab.find(type);
	return spawner->second(manager);
}

ecs::Entity rtypeserver::spawner::Spawner::spawnPlayer(ecs::Manager &manager) {
	auto entity = Spawner::spawn<PlayerSpawner>(manager);
	auto &pos = manager.getEntityComponent<rtype::ct::Position>(entity);
	return entity;
}

*/