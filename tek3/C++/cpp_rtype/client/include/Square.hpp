//
// Square.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/Square.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 10 17:49:54 2018 Anthony LECLERC
// Last update mer. janv. 10 17:49:54 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_SQUARE_HPP
#define CPP_RTYPE_SQUARE_HPP

#include "components/PlayerID.hpp"
#include "Manager.hpp"
#include "components/Position.hpp"
#include "components/Speed.hpp"

namespace rtype {
  class Square {
  private:
	  static rtype::ct::PlayerID _id;
	public:

	  static bool make_net(ecs::Manager& mgr, rtype::ct::PlayerID::Id id,
								   float posx, float posy);

	  static bool make(ecs::Manager& mgr, rtype::ct::PlayerID::Id id,
					 float posx = 0, float posy = 0, unsigned int sprite = 0);

  };

}

#endif //CPP_RTYPE_SQUARE_HPP
