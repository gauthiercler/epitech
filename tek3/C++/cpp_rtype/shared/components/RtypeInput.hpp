//
// RtypeInput.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/RtypeInput.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 10 09:33:27 2018 Anthony LECLERC
// Last update mer. janv. 10 09:33:27 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_PLAYERCOMMAND_HPP
#define CPP_RTYPE_PLAYERCOMMAND_HPP

#include <SFML/Window/Keyboard.hpp>

namespace rtype
{
	namespace ct
	{
		/// @brief Component for keyboard player input.

		struct RtypeInput {

			using value_type = sf::Keyboard::Key;

			value_type Up;
			value_type Down;
			value_type Left;
			value_type Right;
			value_type Fire;
			value_type Charge;

			RtypeInput () = default;

			RtypeInput(value_type vUp, value_type vDown, value_type vLeft, value_type vRight, value_type vFire, value_type vCharge) :
				Up(vUp), Down(vDown), Left(vLeft), Right(vRight), Fire(vFire), Charge(vCharge) {}
			RtypeInput(const RtypeInput &input) : Up(input.Up), Down(input.Down), Left(input.Left), Right(input.Right), Fire(input.Fire), Charge(input.Charge) {};
		};
	}
}

#endif /* CPP_RTYPE_PLAYERCOMMAND_HPP */
