//
// Speed.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/Speed.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 10 09:04:47 2018 Anthony LECLERC
// Last update mer. janv. 10 09:04:47 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_SPEED_HPP
#define CPP_RTYPE_SPEED_HPP

namespace rtype {
	namespace ct {

		/// @brief Component for entities moving in the world.
		/// With systems:
		struct Speed {

		  	float x;
			float y;

			Speed() : x(0), y(0) {};
			Speed(float speedX, float speedY) : x(speedX), y(speedY) {};
		};
	}
}

#endif /* CPP_RTYPE_SPEED_HPP */
