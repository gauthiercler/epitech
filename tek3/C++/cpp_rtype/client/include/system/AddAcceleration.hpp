//
// Created by ventinc on 1/17/18.
//

#ifndef CPP_RTYPE_ADDACCELERATION_HPP
#define CPP_RTYPE_ADDACCELERATION_HPP

#include "system/System.hpp"

namespace rtype {
	class AddAcceleration : public ecs::System {
	public:
		explicit AddAcceleration();
		void process(ecs::Manager& mgr, float elapsedTime) override;
	};
}

#endif //CPP_RTYPE_ACCELERATION_HPP
