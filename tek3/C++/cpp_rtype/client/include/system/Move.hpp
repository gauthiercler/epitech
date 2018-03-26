//
// Move.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/Move.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 10 16:46:54 2018 Anthony LECLERC
// Last update mer. janv. 10 16:46:54 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_MOVE_HPP
#define CPP_RTYPE_MOVE_HPP

#include <system/System.hpp>

namespace rtype {

  class Move : public ecs::System {
  public:
	  	Move();
		void process(ecs::Manager& mgr, float elapsedTime) override;

  };
}


#endif //CPP_RTYPE_MOVE_HPP
