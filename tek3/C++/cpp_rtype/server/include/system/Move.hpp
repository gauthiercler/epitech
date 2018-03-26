//
// Created by ventinc on 1/19/18.
//

#ifndef CPP_RTYPE_MOVE_HPP
#define CPP_RTYPE_MOVE_HPP

#include "system/System.hpp"

namespace rtypeserver {

	class Move : public ecs::System {
	public:
		Move();
		void process(ecs::Manager& mgr, float elapsedTime) override;

	};
}

#endif //CPP_RTYPE_MOVE_HPP
