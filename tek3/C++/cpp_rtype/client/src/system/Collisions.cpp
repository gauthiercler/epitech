//
// Created by ventinc on 1/17/18.
//

#include <client/include/singleton/Window.hpp>
#include "client/include/system/Collisions.hpp"
#include "component/types/ComponentIdGenerator.hpp"
#include "Collide.hpp"
#include "Position.hpp"
#include "Manager.hpp"
#include "BoundingBox.hpp"
#include "Dead.hpp"

rtype::Collisions::Collisions() {
	this->setRequiredComponents({ecs::componentType<ct::Collide>(), ecs::componentType<ct::Position>(), ecs::componentType<ct::BoundingBox>()});
}

void rtype::Collisions::process(ecs::Manager &mgr, float elapsedTime) {
	for (auto &&entity : this->entities) {
		auto &collide = mgr.getEntityComponent<ct::Collide>(entity);
		if (!mgr.hasEntityComponent<ct::Dead>(entity)) {
			switch (collide.type) {
				case ct::Collide::CollideType::BULLET :
					this->collideBullet(mgr, entity); break;
				case ct::Collide::CollideType::PLAYER :
					this->collidePlayer(mgr, entity); break;
				case ct::Collide::CollideType::ENEMY :
					this->collideEnemy(mgr, entity); break;
				default : break;
			}
		}
	}
}

void rtype::Collisions::collideBullet(ecs::Manager &mgr, ecs::Entity entity) {
	for (auto &&e : this->entities) {
		if (!mgr.hasEntityComponent<ct::Dead>(entity)) {
			auto &bulletPos = mgr.getEntityComponent<ct::Position>(entity);
			auto &eType = mgr.getEntityComponent<ct::Collide>(e);

			if (bulletPos.x > WWIDTH || bulletPos.x < 0 || bulletPos.y < 0 || bulletPos.y >= WHEIGHT) {
				mgr.addComponent(entity, ct::Dead());
				mgr.registerEntity(entity);
			} else if (eType.type != ct::Collide::CollideType::BULLET && !mgr.hasEntityComponent<ct::Dead>(e)) {
				auto &bulletSize = mgr.getEntityComponent<ct::BoundingBox>(entity);
				auto &ePos = mgr.getEntityComponent<ct::Position>(e);
				auto &eSize = mgr.getEntityComponent<ct::BoundingBox>(e);

				if (!((ePos.x >= bulletPos.x + bulletSize.width) ||
					(ePos.x + eSize.width <= bulletPos.x) ||
					(ePos.y >= bulletPos.y + bulletSize.height) ||
					(ePos.y + eSize.height <= bulletPos.y))){
					mgr.addComponent(entity, ct::Dead());
					mgr.addComponent(e, ct::Dead());
					mgr.registerEntity(e);
					mgr.registerEntity(entity);
				}
			}
		}
	}
}

void rtype::Collisions::collidePlayer(ecs::Manager &mgr, ecs::Entity entity) {
	auto& position (mgr.getEntityComponent<ct::Position>(entity));
	auto& size (mgr.getEntityComponent<ct::BoundingBox>(entity));

	if (position.x < 0)
		position.x = 0;
	if (position.x > WWIDTH - WWIDTH / 4)
		position.x = WWIDTH - WWIDTH / 4;
	if (position.y < 0)
		position.y = WHEIGHT - size.height;
	else if (position.y + size.height > WHEIGHT)
		position.y = 0;
}

void rtype::Collisions::collideEnemy(ecs::Manager &mgr, ecs::Entity entity) {
	for (auto &&e : this->entities) {
		if (!mgr.hasEntityComponent<ct::Dead>(entity)) {
			auto &enemyPos = mgr.getEntityComponent<ct::Position>(entity);
			auto &enemySize = mgr.getEntityComponent<ct::BoundingBox>(entity);
			auto &eType = mgr.getEntityComponent<ct::Collide>(e);

			if (enemyPos.x < 0) {
				std::cout << "DEAD" << std::endl;
				mgr.addComponent(entity, ct::Dead());
				mgr.registerEntity(entity);
			} else if (eType.type != ct::Collide::CollideType::ENEMY && !mgr.hasEntityComponent<ct::Dead>(e)) {
				auto &ePos = mgr.getEntityComponent<ct::Position>(e);
				auto &eSize = mgr.getEntityComponent<ct::BoundingBox>(e);

				if (!((ePos.x >= enemyPos.x + enemySize.width) ||
					  (ePos.x + eSize.width <= enemyPos.x) ||
					  (ePos.y >= enemyPos.y + enemySize.height) ||
					  (ePos.y + eSize.height <= enemyPos.y))){
					mgr.addComponent(entity, ct::Dead());
					mgr.addComponent(e, ct::Dead());
					mgr.registerEntity(e);
					mgr.registerEntity(entity);
				}
			}
		}
	}
}

