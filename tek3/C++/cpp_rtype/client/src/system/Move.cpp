//
// Move.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/Move.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 10 16:46:54 2018 Anthony LECLERC
// Last update mer. janv. 10 16:46:54 2018 Anthony LECLERC
//

#include "Position.hpp"
#include "Manager.hpp"
#include "Speed.hpp"
#include "system/Move.hpp"

void rtype::Move::process(ecs::Manager& mgr, float elapsedTime)
{
	for (auto& entity : entities) {
		auto& position (mgr.getEntityComponent<rtype::ct::Position>(entity));
		auto& speed (mgr.getEntityComponent<rtype::ct::Speed>(entity));

		auto px = position.x + (speed.x * elapsedTime);
		auto py = position.y + (speed.y * elapsedTime);

		position.x = px;
		position.y = py;
		//TODO Send position with entity
  }
}

rtype::Move::Move() {
	this->setRequiredComponents({ecs::componentType<rtype::ct::Position>(),
								 ecs::componentType<rtype::ct::Speed>()});
}
