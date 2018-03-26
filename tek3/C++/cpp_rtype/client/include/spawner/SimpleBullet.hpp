//
// Created by ventinc on 1/17/18.
//

#ifndef CPP_RTYPE_SIMPLEBULLET_HPP
#define CPP_RTYPE_SIMPLEBULLET_HPP

#include "ISpawner.hpp"

namespace rtype {
	namespace spawner {
		class SimpleBullet : public ecs::ISpawner {
		public:
			~SimpleBullet() override = default;

			ecs::Entity spawn(ecs::Manager &manager, const rtype::ct::Position &pos) const override;
		};
	}
}

#endif //CPP_RTYPE_SIMPLEBULLET_HPP
