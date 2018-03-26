//
// Created by montag_v on 21/01/2018.
//

#ifndef CPP_RTYPE_LIBRARY_HPP
#define CPP_RTYPE_LIBRARY_HPP

#include <limits>

namespace rtype {
	namespace ct {

		/// @brief Component for entities that come from a library
		/// With systems:
		struct Library {

			static const constexpr unsigned int InvalidID = (std::numeric_limits<unsigned int>::max)();
			unsigned int ID;

			explicit Library(unsigned int id) : ID(id) {}
			Library() : ID((std::numeric_limits<unsigned int>::max)()) {}
		};
	}
}

#endif //CPP_RTYPE_LIBRARY_HPP
