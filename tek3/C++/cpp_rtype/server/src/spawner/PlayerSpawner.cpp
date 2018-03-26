//
// Created by ventinc on 1/19/18.
//

#include "BoundingBox.hpp"
#include "Position.hpp"
#include "Manager.hpp"
#include "server/include/spawner/PlayerSpawner.hpp"

ecs::Entity rtypeserver::PlayerSpawner::spawn(
	ecs::Manager& manager,
	const rtype::ct::Position& pos) const
{
	ecs::Entity entity = manager.createEntity();

	manager.addComponent(entity, pos);
	manager.addComponent(entity, rtype::ct::BoundingBox());

	manager.registerEntity(entity);
	return entity;
}
