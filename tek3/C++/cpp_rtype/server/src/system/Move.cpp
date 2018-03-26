//
// Created by ventinc on 1/19/18.
//

#include "server/include/system/Move.hpp"
#include "Position.hpp"
#include "Manager.hpp"
#include "Speed.hpp"

void rtypeserver::Move::process(ecs::Manager& mgr, float elapsedTime)
{
	for (auto& entity : entities) {
		auto& position (mgr.getEntityComponent<rtype::ct::Position>(entity));
		auto& speed (mgr.getEntityComponent<rtype::ct::Speed>(entity));

		auto px = position.x + (speed.x * elapsedTime);
		auto py = position.y + (speed.y * elapsedTime);

		position.x = px;
		position.y = py;
	}
}

rtypeserver::Move::Move() {
	this->setRequiredComponents({ecs::componentType<rtype::ct::Position>(),
								 ecs::componentType<rtype::ct::Speed>()});
}
