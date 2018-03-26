//
// Created by ventinc on 1/19/18.
//

#ifndef CPP_RTYPE_SPAWNER_HPP
#define CPP_RTYPE_SPAWNER_HPP

#include <unordered_map>
#include <shared/EntityType.hpp>
#include <util.hpp>
#include <functional>
#include "ISpawner.hpp"

namespace rtypeserver {
    namespace spawner {
/*        class Spawner {
        public:
            template <typename S>
            static ecs::Entity spawn(ecs::Manager &manager) {
                static_assert(std::is_base_of<ecs::ISpawner, S>::value, "S must be derived from ISpawner");

                auto spawner = S();
                return spawner.spawn(manager);
            }

            Spawner();
            ~Spawner() = default;

            ecs::Entity		spawnPlayer(ecs::Manager &manager);
            ecs::Entity		spawn(ecs::Manager &manager, rtype::EntityType type);

		private:
			std::unordered_map<rtype::EntityType, std::function<ecs::Entity(ecs::Manager &)>, rtype::util::EnumClassHash > funcTab;

		};*/
    }
}

#endif //CPP_RTYPE_SPAWNER_HPP
