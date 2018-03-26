//
// Created by ventinc on 1/17/18.
//

#ifndef CPP_RTYPE_STARFIELD_HPP
#define CPP_RTYPE_STARFIELD_HPP

#include <system/System.hpp>
#include <chrono>

#ifndef STARFIELDINTERVAL
# define STARFIELDINTERVAL (0.05)
#endif

#ifndef STARFIELDENTITIES
# define STARFIELDENTITIES (200)
#endif

namespace rtype {

	class Starfield : public ecs::System {
	public:
		Starfield();
		void process(ecs::Manager& mgr, float elapsedTime) override;

	private:
		float interval = STARFIELDINTERVAL;
	};
}

#endif //CPP_RTYPE_STARFIELD_HPP
