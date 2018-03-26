//
// Created by ventinc on 1/17/18.
//

#include <SFML/Graphics/Color.hpp>
#include <random>
#include <Dead.hpp>
#include "client/include/spawner/Spawner.hpp"
#include "client/include/spawner/StarSpawner.hpp"
#include "Star.hpp"
#include "Position.hpp"
#include "Speed.hpp"
#include "BoundingBox.hpp"
#include "client/include/singleton/Window.hpp"
#include "client/include/system/Starfield.hpp"

rtype::Starfield::Starfield() {
	this->setRequiredComponents({
									ecs::componentType<ct::Star>(),
									ecs::componentType<ct::Position>(),
									ecs::componentType<sf::Color>(),
									ecs::componentType<ct::Speed>(),
									ecs::componentType<ct::BoundingBox>()
								});
}

void rtype::Starfield::process(ecs::Manager &mgr, float elapsedTime) {
	this->interval -= elapsedTime;
	if (this->interval <= 0 && entities.size() <= STARFIELDENTITIES) {
		std::random_device r;
		std::default_random_engine er(r());
		std::uniform_int_distribution<int> rand_pos(0, WHEIGHT);
		std::uniform_int_distribution<unsigned int> rand_size(2, 6);
		std::uniform_int_distribution<int> rand_speed(200, 300);
		int posr = rand_pos(er);
		rtype::ct::Position pos(WWIDTH, posr);
		ecs::Entity star = spawner::StarSpawner().spawn(mgr, pos);
		unsigned int sizer = rand_size(er);
		float speedr = rand_speed(er);
		auto &size = mgr.getEntityComponent<ct::BoundingBox>(star);
		auto &speed = mgr.getEntityComponent<ct::Speed>(star);

		size.width = sizer;
		size.height = sizer;
		speed.x -= speedr;
		this->interval = STARFIELDINTERVAL;
	}
	for (auto &&entity : entities) {
		auto &pos = mgr.getEntityComponent<ct::Position>(entity);
		if (pos.x < 0) {
			mgr.addComponent(entity, ct::Dead());
			mgr.registerEntity(entity);
		}
	}
}
