//
// Created by ventinc on 1/17/18.
//

#ifndef CPP_RTYPE_COLLISIONS_HPP
#define CPP_RTYPE_COLLISIONS_HPP

#include <system/System.hpp>

namespace rtype {
	class Collisions : public ecs::System {
	public:
		explicit Collisions();
		void process(ecs::Manager& mgr, float elapsedTime) override;

	private:
		void collideBullet(ecs::Manager &mgr, ecs::Entity entity);
		void collidePlayer(ecs::Manager &mgr, ecs::Entity entity);
		void collideEnemy(ecs::Manager &mgr, ecs::Entity entity);
	};
}


#endif //CPP_RTYPE_COLLISIONS_HPP
