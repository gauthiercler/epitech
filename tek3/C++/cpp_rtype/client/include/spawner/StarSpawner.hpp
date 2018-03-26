//
// Created by ventinc on 1/17/18.
//

#ifndef CPP_RTYPE_STARSPAWNER_HPP
#define CPP_RTYPE_STARSPAWNER_HPP

#include <ISpawner.hpp>

namespace rtype {
	namespace spawner {
		class StarSpawner : public ecs::ISpawner {
		public:
			StarSpawner() = default;
			ecs::Entity spawn(ecs::Manager &manager, const rtype::ct::Position &pos) const override;
		};
	}
}

#endif //CPP_RTYPE_STARSPAWNER_HPP
