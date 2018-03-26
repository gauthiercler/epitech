//
// Created by montag-v on 1/17/18.
//

#include <SFML/Graphics/Color.hpp>
#include <BoundingBox.hpp>
#include <Collide.hpp>
#include <Position.hpp>
#include <Speed.hpp>
#include <Acceleration.hpp>
#include <Life.hpp>
#include <LifeTime.hpp>
#include <Library.hpp>
#include "LittleEnemy.hpp"

void ctor() {}

void dtor() {}

ecs::Entity rtype::spawner::LittleEnemy::spawn(ecs::Manager &manager, const rtype::ct::Position &pos) const {
	auto entity = manager.createEntity();

	manager.addComponent(entity, sf::Color(240,240,240));
	manager.addComponent(entity, ct::BoundingBox(10, 10));
	manager.addComponent(entity, ct::Collide(ct::Collide::CollideType::ENEMY));
	manager.addComponent(entity, pos);
	manager.addComponent(entity, ct::Speed(10, 0));
	manager.addComponent(entity, ct::Acceleration(1, 0));
	manager.addComponent(entity, ct::Life(1));
	manager.addComponent(entity, ct::LifeTime());
	manager.addComponent(entity, ct::Library());

	manager.registerEntity(entity);
	return entity;
}

const ecs::ISpawner *rtype::spawner::getSpawner() {
	static rtype::spawner::LittleEnemy spawner;
	return &spawner;
}