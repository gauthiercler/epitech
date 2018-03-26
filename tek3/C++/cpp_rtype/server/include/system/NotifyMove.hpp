//
// NotifyMove.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/NotifyMove.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  dim. janv. 21 11:21:39 2018 Anthony LECLERC
// Last update dim. janv. 21 11:21:39 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_NOTIFYMOVE_HPP
#define CPP_RTYPE_NOTIFYMOVE_HPP

#include <system/System.hpp>
#include "Player.hpp"

namespace rtypeserver {
	class NotifyMove : public ecs::System {
	public:
		NotifyMove(std::vector<std::shared_ptr<Player> >& );

		virtual void
		process(ecs::Manager& mgr, float elapsedTime) override;
	private:

		std::vector<std::shared_ptr<Player> >& _players;
	};
}


#endif //CPP_RTYPE_NOTIFYMOVE_HPP
