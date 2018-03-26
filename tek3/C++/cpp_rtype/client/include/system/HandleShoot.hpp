//
// Created by ventinc on 1/17/18.
//

#ifndef CPP_RTYPE_SHOOT_HPP
#define CPP_RTYPE_SHOOT_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "system/System.hpp"

namespace rtype {

	class HandleShoot : public ecs::System {
	public:
		HandleShoot();
		void process(ecs::Manager& mgr, float elapsedTime) override;

	private:
		bool hasCommand(long command, long what);
	};
}

#endif //CPP_RTYPE_SHOOT_HPP
