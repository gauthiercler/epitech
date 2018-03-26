//
// Created by montag_v on 20/01/2018.
//

#ifndef CPP_RTYPE_LIFETIME_HPP
#define CPP_RTYPE_LIFETIME_HPP

#include <limits>

namespace rtype {
	namespace ct {

		/// @brief Component for entities that have a durability.
		/// With systems:
		struct LifeTime  {
			float time;
			float timeBeforeDeath;

			LifeTime(float offset, float timeToLive) : time(offset), timeBeforeDeath(timeToLive) {}
			LifeTime(float offset) : time(offset), timeBeforeDeath((std::numeric_limits<float>::max)()) {}
			LifeTime() : time(0), timeBeforeDeath((std::numeric_limits<float>::max)()) {}
		};
	}
}

#endif //CPP_RTYPE_LIFETIME_HPP
