//
// Created by ventinc on 1/17/18.
//

#ifndef CPP_RTYPE_DEATH_HPP
#define CPP_RTYPE_DEATH_HPP

#include <system/System.hpp>

namespace rtype {
	class Death : public ecs::System {
	public:
		explicit Death();
		void process(ecs::Manager& mgr, float elapsedTime) override;
	};
}

#endif //CPP_RTYPE_DEATH_HPP
