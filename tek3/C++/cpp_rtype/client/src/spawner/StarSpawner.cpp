//
// Created by ventinc on 1/17/18.
//

#include <SFML/Graphics/Color.hpp>
#include <Drawable.hpp>
#include "Speed.hpp"
#include "Position.hpp"
#include "Star.hpp"
#include "BoundingBox.hpp"
#include "client/include/spawner/StarSpawner.hpp"

ecs::Entity rtype::spawner::StarSpawner::spawn(ecs::Manager &manager, const rtype::ct::Position &pos) const {
	ecs::Entity entity = manager.createEntity();

	manager.addComponent(entity, pos);
	manager.addComponent(entity, ct::Star());
	manager.addComponent(entity, ct::BoundingBox());
	manager.addComponent(entity, sf::Color(255,255,255, 190));
	manager.addComponent(entity, ct::Speed());
	manager.addComponent(entity, ct::Drawable());

	manager.registerEntity(entity);
	return entity;
}
