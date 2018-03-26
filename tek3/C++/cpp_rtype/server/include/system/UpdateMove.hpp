//
// UpdateMove.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/UpdateMove.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  dim. janv. 21 11:09:45 2018 Anthony LECLERC
// Last update dim. janv. 21 11:09:45 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_UPDATEMOVE_HPP
#define CPP_RTYPE_UPDATEMOVE_HPP

#include <system/System.hpp>
#include "shared_queue/shared_storage.hpp"
#include <packet/MovePacket.hpp>

namespace rtypeserver {
	class UpdateMove : public ecs::System {

	public:
		UpdateMove(rnetwork::shared_queue<rnetwork::packet::MovePacket>& packets);

		virtual void
		process(ecs::Manager& mgr, float elapsedTime) override;

	private:
		rnetwork::shared_queue<rnetwork::packet::MovePacket>& _sq;
	};
}


#endif //CPP_RTYPE_UPDATEMOVE_HPP
