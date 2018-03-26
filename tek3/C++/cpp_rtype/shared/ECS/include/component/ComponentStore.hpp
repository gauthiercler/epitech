//
// Created by ventinc on 1/9/18.
//

#ifndef CPP_RTYPE_COMPONENTSTORE_HPP
#define CPP_RTYPE_COMPONENTSTORE_HPP

#include <memory>
#include <unordered_map>
#include <algorithm>
#include "Export.hpp"
#include "Entity.hpp"
#include "ComponentType.hpp"

namespace ecs {

	class Manager;

    class RTECS_API IComponentStore {
    public:
      IComponentStore() = default;
      ~IComponentStore() = default;
      IComponentStore(IComponentStore const&) = default;
      IComponentStore(IComponentStore&&) noexcept = default;

#ifdef WIN32
		using Ptr = std::shared_ptr<IComponentStore>;

		template<typename TImpl, typename ...Args>
		static Ptr makePtr(Args&& ...args)
		{
			return std::make_shared<TImpl>(std::forward<Args>(args)...);
		}

#else
		using Ptr = std::unique_ptr<IComponentStore>;

		template<typename TImpl, typename ...Args>
		static Ptr makePtr(Args&& ...args)
		{
			return std::make_unique<TImpl>(std::forward<Args>(args)...);
		}
#endif


    };

    template <typename C>
    class ComponentStore : public IComponentStore {

    public:
		ComponentStore() = default;
      		ComponentStore(ComponentStore<C> const&) = default;
      		ComponentStore(ComponentStore<C>&&) noexcept = default;
		~ComponentStore() = default;

		inline bool	add(const Entity entity, C&& component) {
		    return this->store.insert(std::make_pair(entity, std::move(component))).second;
		}

		inline bool add(const Entity entity, C const& component) {
			return this->store.insert(std::make_pair(entity, component)).second;
		}

		inline bool	remove(const Entity entity) {
			return (0 < this->store.erase(entity));
		}

		inline void removeNotIn(std::unordered_map<Entity, ComponentTypeSet>  &entities) {
			for(auto it = this->store.begin(); it != this->store.end();)
			{
				if (!(entities.end() != entities.find(it->first)))
					it = this->store.erase(it);
				else
					++it;
			}
		}

		inline bool	has(const Entity entity) {
		    return (this->store.end() != this->store.find(entity));
		}

		inline C	&get(const Entity entity) {
		    return this->store.at(entity);
		}

		C	extract(const Entity entity) {
			C component = std::move(this->store.at(entity));
			this->store.erase(entity);
			return component;
		}

    private:
		std::unordered_map<Entity, C> store;
    };

}

#endif //CPP_RTYPE_COMPONENTSTORE_HPP
