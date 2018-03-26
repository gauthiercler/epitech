//
// UpdateNetworkMove.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/UpdateNetworkMove.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  dim. janv. 21 13:09:27 2018 Anthony LECLERC
// Last update dim. janv. 21 13:09:27 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_UPDATENETWORKMOVE_HPP
#define CPP_RTYPE_UPDATENETWORKMOVE_HPP

#include <system/System.hpp>
#include <shared_queue/shared_storage.hpp>
#include <packet/MovePacket.hpp>

namespace rtype {

	class UpdateNetworkMove : public ecs::System {
	public:
		UpdateNetworkMove(rnetwork::shared_queue<rnetwork::packet::MovePacket>& sq);

		virtual void
		process(ecs::Manager& mgr, float elapsedTime) override;
	private:
		rnetwork::shared_queue<rnetwork::packet::MovePacket>& _sq;
	};

}


#endif //CPP_RTYPE_UPDATENETWORKMOVE_HPP
