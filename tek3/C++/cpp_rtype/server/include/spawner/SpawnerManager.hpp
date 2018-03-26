//
// Created by montag_v on 21/01/2018.
//

#ifndef CPP_RTYPE_SPAWNERMANAGER_HPP
#define CPP_RTYPE_SPAWNERMANAGER_HPP

#include <Manager.hpp>
#include <ISpawner.hpp>

namespace rtypeserver {

	class SpawnerManager {

		ecs::Manager					&_manager;
		std::vector<ecs::ISpawner *>	_spawners;
		std::vector<float>				_cooldowns;
		std::vector<float>				_elapsedTimes;

	public:

		using SpawnerID = size_t;

		SpawnerManager(ecs::Manager &manager);
		~SpawnerManager();

		void addSpawner(ecs::ISpawner *spawner);
		void addSpawners(const std::vector<ecs::ISpawner *> &spawners);
		void removeSpawner(ecs::ISpawner *spawner);
		void removeSpawner(SpawnerID id);
		void clear();
		size_t size();

		ecs::Entity spawnEntity(SpawnerID ID, const rtype::ct::Position& pos = {0, 0}) const;
		void updateSpawners(float elapsedTime);
	};

}

#endif //CPP_RTYPE_SPAWNERMANAGER_HPP
