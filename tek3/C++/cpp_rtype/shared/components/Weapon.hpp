//
// ProjectileGenerator.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/ProjectileGenerator.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  dim. janv. 21 08:06:27 2018 Anthony LECLERC
// Last update dim. janv. 21 08:06:27 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_WEAPON_HPP
#define CPP_RTYPE_WEAPON_HPP

#include <ISpawner.hpp>

namespace rtype {
	namespace ct {
		struct Weapon {

			std::unique_ptr<ecs::ISpawner> spawner;
			float interval;
			float last;
			bool autoFired;

			Weapon() : spawner(nullptr), interval(0.2f), last(0), autoFired(false) {}
			Weapon(std::unique_ptr<ecs::ISpawner> __spawner,
			float __interval = 0.2,
			bool __autofired = false) : spawner(std::move(__spawner)),
				interval(__interval),
				last(0),
				autoFired(__autofired)
			{}
		};
	}
}

#endif /* CPP_RTYPE_PROJECTILEGENERATOR_HPP */
