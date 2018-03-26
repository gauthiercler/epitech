//
// Created by ventinc on 1/17/18.
//

#include <Speed.hpp>
#include <Acceleration.hpp>
#include <SFML/Graphics/Color.hpp>
#include <BoundingBox.hpp>
#include <Collide.hpp>
#include "Position.hpp"
#include "client/include/spawner/SimpleBullet.hpp"

ecs::Entity rtype::spawner::SimpleBullet::spawn(ecs::Manager &manager, const rtype::ct::Position &pos) const {
	auto entity = manager.createEntity();

	manager.addComponent(entity, pos);
	manager.addComponent(entity, sf::Color(255,0,0));
	manager.addComponent(entity, ct::BoundingBox(10, 2));
	manager.addComponent(entity, ct::Collide(ct::Collide::CollideType::BULLET));
	manager.addComponent(entity, ct::Speed(1000, 0));

	manager.registerEntity(entity);
	return entity;
}
