//
// Created by ventinc on 1/12/18.
//

#ifndef CPP_RTYPE_FPS_HPP
#define CPP_RTYPE_FPS_HPP

#include <system/System.hpp>

namespace rtype {
	class FPSCalculator : public ecs::System {
	public:
		explicit FPSCalculator();
		void process(ecs::Manager& mgr, float elapsedTime) override;
	};
}

#endif //CPP_RTYPE_FPS_HPP
