//
// Position.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/Position.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 10 09:03:29 2018 Anthony LECLERC
// Last update mer. janv. 10 09:03:29 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_POSITION_HPP
#define CPP_RTYPE_POSITION_HPP

namespace rtype {
	namespace ct {

		/// @brief Component for entities with a position in the world.
		/// With systems:
		struct Position  {
		  	float x;
		  	float y;

			Position(float xPos, float yPos) : x(xPos), y(yPos) {}
			Position() : x(0), y(0) {}
		};
	}
}

#endif /* CPP_RTYPE_POSITION_HPP */
