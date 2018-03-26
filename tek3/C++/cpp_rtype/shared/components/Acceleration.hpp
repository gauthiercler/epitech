//
// AddAcceleration.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/AddAcceleration.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 10 09:11:49 2018 Anthony LECLERC
// Last update mer. janv. 10 09:11:49 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_ACCELERATION_HPP
#define CPP_RTYPE_ACCELERATION_HPP

namespace rtype {
	namespace ct {
		/// @brief For entities with variable speed.
		struct Acceleration {
	  		float x;
	  		float y;

			Acceleration(float x, float y) : x(x), y(y) {}
		};
	}
}

#endif /* CPP_RTYPE_ACCELERATION_HPP */
