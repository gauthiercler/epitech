//
// Created by montag_v on 21/01/2018.
//

#include <Library.hpp>
#include "spawner/SpawnerManager.hpp"

rtypeserver::SpawnerManager::SpawnerManager(ecs::Manager &manager)
	: _manager(manager)
{}

rtypeserver::SpawnerManager::~SpawnerManager()
{
	clear();
}

void rtypeserver::SpawnerManager::addSpawner(ecs::ISpawner *spawner) {
	_cooldowns.emplace_back(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/6) + 1));
	std::cout << "Cooldown for spawner " << _cooldowns.size() << " of : " << _cooldowns.back() << std::endl;
	_elapsedTimes.emplace_back(0);
	_spawners.emplace_back(spawner);
}

void rtypeserver::SpawnerManager::addSpawners(const std::vector<ecs::ISpawner *> &spawners) {
	for (auto spawn : spawners)
		addSpawner(spawn);
}

void rtypeserver::SpawnerManager::removeSpawner(ecs::ISpawner *spawner) {
	auto it = std::find(_spawners.begin(), _spawners.end(), spawner);
	if (it != std::end(_spawners))
		_spawners.erase(it);
}

void rtypeserver::SpawnerManager::removeSpawner(rtypeserver::SpawnerManager::SpawnerID id) {
	_spawners.erase(_spawners.begin() + id);
}

void rtypeserver::SpawnerManager::clear() {
	_spawners.clear();
}

size_t rtypeserver::SpawnerManager::size() {
	return (_spawners.size());
}

ecs::Entity rtypeserver::SpawnerManager::spawnEntity(rtypeserver::SpawnerManager::SpawnerID ID, const rtype::ct::Position &pos) const {
	auto entity = _spawners[ID]->spawn(_manager, pos);

	auto &libraryID = _manager.getEntityComponent<rtype::ct::Library>(entity);
	libraryID.ID = ID;
	return entity;
}

void rtypeserver::SpawnerManager::updateSpawners(float el) {
	for (auto i = 0; i < _elapsedTimes.size(); i++) {
		_elapsedTimes[i] += el;
		if (_elapsedTimes[i] > _cooldowns[i]) {
			spawnEntity(static_cast<size_t>(i), {1500, (static_cast <float> (rand()) / (static_cast <float> (RAND_MAX))) * 700 + 100});
			_elapsedTimes[i] = 0;
		}
	}
}
