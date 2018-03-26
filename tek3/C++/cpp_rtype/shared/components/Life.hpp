//
// Created by montag_v on 20/01/2018.
//

#ifndef CPP_RTYPE_LIFE_HPP
#define CPP_RTYPE_LIFE_HPP

namespace rtype {
	namespace ct {

		/// @brief Component for entities with an amount of life
		/// With systems:
		struct Life  {
			unsigned int amount;

			Life(unsigned int lifeAmount) : amount(lifeAmount) {}
			Life() : amount(0) {}
		};
	}
}

#endif //CPP_RTYPE_LIFE_HPP
