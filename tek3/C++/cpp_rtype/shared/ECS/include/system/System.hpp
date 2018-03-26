//
// Created by ventinc on 1/9/18.
//

#ifndef CPP_RTYPE_SYSTEM_HPP
#define CPP_RTYPE_SYSTEM_HPP

#include <memory>
#include "Export.hpp"
#include "component/ComponentType.hpp"
#include "Entity.hpp"

namespace ecs {
	class Manager;

	class RTECS_API System {

		public:

		typedef std::shared_ptr<System> Ptr;

		System() = default;
		virtual ~System() = default;

		inline const	ComponentTypeSet& getRequiredComponents() const {
			return this->requiredComponents;
		}
		inline bool		registerEntity(Entity entity) {
			return this->entities.insert(entity).second;
		}
		inline bool		unregisterEntity(Entity entity) {
			return (this->entities.erase(entity) == 1);
		}
		inline bool		hasEntity(Entity entity) {
			return (this->entities.end() != this->entities.find(entity));
		}

		virtual void	process(Manager& mgr, float elapsedTime) = 0;

		protected:

		inline void		setRequiredComponents(ComponentTypeSet&& requiredComponents) {
			this->requiredComponents = std::move(requiredComponents);
		}

		std::set<Entity>	entities;

		private:

		ComponentTypeSet	requiredComponents;
	};
}

#endif //CPP_RTYPE_SYSTEM_HPP
