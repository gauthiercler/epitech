//
// Created by ventinc on 1/17/18.
//

#include <chrono>
#include <Speed.hpp>
#include <Weapon.hpp>
#include <BoundingBox.hpp>
#include "spawner/Spawner.hpp"
#include "spawner/SimpleBullet.hpp"
#include "Position.hpp"
#include "RtypeCommand.hpp"
#include "Weapon.hpp"
#include "component/types/ComponentIdGenerator.hpp"
#include "system/HandleShoot.hpp"
#include "Manager.hpp"

rtype::HandleShoot::HandleShoot() {
	this->setRequiredComponents({ecs::componentType<ct::Weapon>(),
								 ecs::componentType<ct::RtypeCommand>(),
								 ecs::componentType<ct::Position>(),
								 ecs::componentType<ct::BoundingBox>()});
}

void rtype::HandleShoot::process(ecs::Manager &mgr, float elapsedTime) {
	for (auto&& entity : entities) {

		auto command = mgr.getEntityComponent<ct::RtypeCommand>(entity);

		using InputType = decltype(command);
		auto input = command.input;
		auto &weapon = mgr.getEntityComponent<ct::Weapon >(entity);

		if (weapon.last < weapon.interval)
			weapon.last += elapsedTime;

		if (this->hasCommand(input, InputType::Fire) || weapon.autoFired) {
			if (weapon.last >= weapon.interval) {

				auto &pos = mgr.getEntityComponent<ct::Position>(entity);
				auto &size = mgr.getEntityComponent<ct::BoundingBox>(entity);

				ct::Position spawnPos (pos.x + size.width, pos.y + size.height / 2);
				if (weapon.spawner)
					weapon.spawner->spawn(mgr, spawnPos);

				weapon.last -= weapon.interval;
			}
		}
	}
}

bool rtype::HandleShoot::hasCommand(long command, long what) {
	return (command & what) != 0;
}
