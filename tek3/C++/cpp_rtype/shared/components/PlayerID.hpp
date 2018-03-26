//
// PlayerID.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/PlayerID.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 10 09:26:40 2018 Anthony LECLERC
// Last update mer. janv. 10 09:26:40 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_PLAYERID_HPP
#define CPP_RTYPE_PLAYERID_HPP

namespace rtype {
	namespace ct {

		/// @brief Colors for RType players in multiplayer.
		struct PlayerID {
			enum Id{
				BLUE,
				RED,
				YELLOW,
				GREEN
			};

			Id id;
		};
	}
}

#endif /* CPP_RTYPE_PLAYERID_HPP */
