//
// Created by ventinc on 1/9/18.
//

#ifndef CPP_RTYPE_MANAGER_HPP
#define CPP_RTYPE_MANAGER_HPP

#include <map>
#include <vector>
#include <unordered_map>
#include <limits>
#include <cassert>
#include <util/traits.hpp>
#include <iostream>
#include <component/IdGenerator.hpp>
#include <string>
#include <utility>
#include <component/types/ComponentIdGenerator.hpp>
#include "Export.hpp"
#include "component/ComponentStore.hpp"
#include "system/System.hpp"

namespace ecs {
	class RTECS_API Manager {

		public:
		Manager() = default;
		~Manager() = default;

		template <typename C>
		bool				createComponentStore() {
			auto ctype = ComponentTypeId<C>::make();
			if (ctype == InvalidComponentType)
				return false;
			return this->componentStores
					   .insert(std::make_pair(
						   ctype,
						   IComponentStore::makePtr<ComponentStore<C> >()))
					   .second;
		}

		template <typename C>
		ComponentStore<C>	&getComponentStore() {
			auto ctype = componentType<C>();
			if (ctype == InvalidComponentType)
				throw std::runtime_error("The ComponentStore " + std::to_string(ctype) + " does not exist");
			auto& iComponentStore = this->componentStores.at(ctype);
			return reinterpret_cast<ComponentStore<C>&>(*iComponentStore);
		}

		template<typename C>
		C& getEntityComponent(Entity e) {
			return this->getComponentStore<C>().get(e);
		}

		template<typename C>
		bool hasEntityComponent(Entity e) {
			return this->getComponentStore<C>().has(e);
		}

		template <typename Cv>
		bool				addComponent(Entity entity, Cv &&component) {
		  using C = ecs::remove_cvref<Cv>;


			auto ctype = componentType<C>();
			auto entt = this->entities.find(entity);
			if (this->entities.end() == entt) {
				throw std::runtime_error("The Entity does not exist");
			}
			entt->second.insert(ctype);
			getComponentStore<C>().removeNotIn(this->entities);
			return getComponentStore<C>().add(entity, std::forward<Cv>(component));
		}

		void				addSystem(System::Ptr const& system);
		Entity				createEntity();
		const std::unordered_map<Entity, ComponentTypeSet> &getEntities();
		bool				hasEntity(Entity entity);
		size_t				registerEntity(Entity entity);
		size_t				unregisterEntity(Entity entity, bool canErase = false);

		size_t				unregisterEntityExpect(Entity entity, const ComponentTypeSet &componentSets, bool canErase = false);

		void				processSystems(float elapsedTime);
		void				reset();
		void				setEnded(bool value);
		bool				isEnded() const;

	private:
		Entity											lastEntity {};
		std::unordered_map<Entity, ComponentTypeSet>    entities;
		std::map<ComponentType, IComponentStore::Ptr>   componentStores;
		std::vector<System::Ptr>						systems;
		bool											ended {false};
	};
}


#endif //CPP_RTYPE_MANAGER_HPP
