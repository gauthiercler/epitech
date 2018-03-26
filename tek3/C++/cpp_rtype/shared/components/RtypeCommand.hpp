//
// RtypeCommand.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/RtypeCommand.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 10 09:16:13 2018 Anthony LECLERC
// Last update mer. janv. 10 09:16:13 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_PLAYERINPUT_HPP
#define CPP_RTYPE_PLAYERINPUT_HPP

namespace rtype {
	namespace ct {
		struct RtypeCommand {

			/// @brief Bitfields for move
			static constexpr const long Up = 1;
			static constexpr const long Down = 1 << 1;
			static constexpr const long Left = 1 << 2;
			static constexpr const long Right = 1 << 3;

			/// @brief Bitfields for firing commands.
			static constexpr const long Fire = 1 << 4;

			static constexpr const long Charge = 1 << 5;

			/// @brief Bitmasks for easier use
			static constexpr const long MoveMask = Up | Down | Left | Right;
			static constexpr const long VerticalMoveMask = Up | Down;
			static constexpr const long HorizontalMoveMask = Left | Right;
			static constexpr const long FireMask = Fire | Charge;

			/// @brief Bitset of constants above.
			long input;
			bool triggered { false };

			RtypeCommand() : input(0) {}
			RtypeCommand(long __input) : input(__input) {}

		};
	}
}

#endif /* CPP_RTYPE_PLAYERINPUT_HPP */
