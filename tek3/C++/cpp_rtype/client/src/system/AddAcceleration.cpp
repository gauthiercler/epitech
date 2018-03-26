//
// Created by ventinc on 1/17/18.
//

#include "component/types/ComponentIdGenerator.hpp"
#include "Speed.hpp"
#include "Acceleration.hpp"
#include "Manager.hpp"
#include "client/include/system/AddAcceleration.hpp"

rtype::AddAcceleration::AddAcceleration() {
	this->setRequiredComponents({ecs::componentType<ct::Speed>(), ecs::componentType<ct::Acceleration>()});
}

void rtype::AddAcceleration::process(ecs::Manager &mgr, float elapsedTime) {
	for (auto &&entity : entities) {
		auto &speed = mgr.getEntityComponent<ct::Speed>(entity);
		auto &acceleration = mgr.getEntityComponent<ct::Acceleration>(entity);

		speed.x = speed.x + acceleration.x;
		speed.y = speed.y + acceleration.y;
	}
}
