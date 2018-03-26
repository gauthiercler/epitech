//
// UpdateNetworkMove.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/UpdateNetworkMove.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  dim. janv. 21 13:09:27 2018 Anthony LECLERC
// Last update dim. janv. 21 13:09:27 2018 Anthony LECLERC
//

#include <client/include/singleton/ServerId.hpp>
#include "client/include/system/UpdateNetworkMove.hpp"
#include "Manager.hpp"

void rtype::UpdateNetworkMove::process(ecs::Manager& mgr, float elapsedTime)
{
	_sq.for_all([&](rnetwork::packet::MovePacket& p) {
		auto clientid = Singleton<ServerId>::get().fromServerId(p.getPlayerId());

		std::clog << "[Update network] :: ServerID == " << p.getPlayerId() <<
			" | ClientID == " << clientid << std::endl;
		if (clientid == ecs::InvalidEntity)
			return ;
		if (this->hasEntity(clientid))
		{
			std::clog << "Entity registered" << std::endl;
		}
		auto& vel = mgr.getEntityComponent<rtype::ct::Speed>(clientid);
		auto& pos = mgr.getEntityComponent<rtype::ct::Position>(clientid);

		auto svel = p.getSpeed();
		auto spos = p.getPosition();

		vel.x = svel.x;
		vel.y = svel.y;
		pos.x = spos.x;
		pos.y = spos.y;
	});
}

rtype::UpdateNetworkMove::UpdateNetworkMove(rnetwork::shared_queue<rnetwork::packet::MovePacket>& sq) :
_sq(sq)
{
	setRequiredComponents( { ecs::componentType<rtype::ct::Position>(),
							 ecs::componentType<rtype::ct::Speed>() } );
}
