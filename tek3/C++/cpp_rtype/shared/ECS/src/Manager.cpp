//
// Created by ventinc on 1/9/18.
//

#include <algorithm>
#include "Manager.hpp"

void ecs::Manager::addSystem(ecs::System::Ptr const& system) {
	if ((!system) || (system->getRequiredComponents().empty())) {
		throw std::runtime_error("System shall specified required Components");
	}
	systems.push_back(system);
}

ecs::Entity ecs::Manager::createEntity() {
	assert(this->lastEntity < std::numeric_limits<Entity>::max());
	this->entities.insert(std::make_pair((this->lastEntity + 1), ComponentTypeSet()));
	return (++this->lastEntity);
}

size_t ecs::Manager::registerEntity(const ecs::Entity entity) {
	size_t associatedSystems = 0;

	auto entt = this->entities.find(entity);
	if (this->entities.end() == entt) {
		throw std::runtime_error("The Entity does not exist");
	}
	auto entityComponents = entt->second;

	for (const auto &system : this->systems) {
		auto systemRequiredComponents = system->getRequiredComponents();
		if (std::includes(entityComponents.begin(), entityComponents.end(),
						  systemRequiredComponents.begin(), systemRequiredComponents.end())) {
			if (!system->hasEntity(entity))
				system->registerEntity(entity);
			++associatedSystems;
		}
	}
	return associatedSystems;
}

size_t ecs::Manager::unregisterEntity(const ecs::Entity entity, bool canErase) {
	size_t associatedSystems = 0;

	auto entt = this->entities.find(entity);
	if (this->entities.end() == entt) {
		throw std::runtime_error("The Entity does not exist");
	}
	for (auto&& system : this->systems) {
		associatedSystems += system->unregisterEntity(entity);
	}
	if (canErase)
		this->entities.erase(entt);

	return associatedSystems;
}

void ecs::Manager::processSystems(float elapsed)
{
	for (auto&& system : this->systems) {
		if (!this->ended)
			system->process(*this, elapsed);
	}
}

bool ecs::Manager::hasEntity(ecs::Entity entity) {
	return (this->entities.end() != this->entities.find(entity));
}

bool ecs::Manager::isEnded() const {
	return this->ended;
}

void ecs::Manager::reset() {
	for (auto ent = entities.begin(); ent != entities.end();) {
		this->unregisterEntity(ent->first);
		ent = entities.erase(ent);
	}
	this->lastEntity = 0;
	this->ended = false;
}

void ecs::Manager::setEnded(bool value) {
	this->ended = value;
}

size_t ecs::Manager::unregisterEntityExpect(ecs::Entity entity, const ecs::ComponentTypeSet &componentSets, bool canErase) {
	size_t associatedSystems = 0;

	auto entt = this->entities.find(entity);
	if (this->entities.end() == entt) {
		throw std::runtime_error("The Entity does not exist");
	}
	for (auto&& system : this->systems) {
		auto systemRequiredComponents = system->getRequiredComponents();
		if (!std::includes(componentSets.begin(), componentSets.end(),
						   systemRequiredComponents.begin(), systemRequiredComponents.end()))
			associatedSystems += system->unregisterEntity(entity);
	}
	this->entities.erase(entt);

	return associatedSystems;
}

const std::unordered_map<ecs::Entity, ecs::ComponentTypeSet> &ecs::Manager::getEntities() {
	return this->entities;
}

