//
// Created by ventinc on 1/17/18.
//

#ifndef CPP_RTYPE_SPAWNER_HPP
#define CPP_RTYPE_SPAWNER_HPP

#include <shared/EntityType.hpp>
#include "ISpawner.hpp"

namespace rtype {
	namespace spawner {
		/*
		class Spawner {
		public:
			template <typename S>
			static ecs::Entity spawn(ecs::Manager &manager, const rtype::ct::Position &pos) {
				static_assert(std::is_base_of<ecs::ISpawner, S>::value, "S must be derived from ISpawner");

				auto spawner = S();
				return spawner.spawn(manager, pos);
			}
		};
		 */
	}
}

#endif //CPP_RTYPE_SPAWNER_HPP
