//
// UpdateMove.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/UpdateMove.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  dim. janv. 21 11:09:45 2018 Anthony LECLERC
// Last update dim. janv. 21 11:09:45 2018 Anthony LECLERC
//

#include "Manager.hpp"
#include "server/include/system/UpdateMove.hpp"

void rtypeserver::UpdateMove::process(ecs::Manager& mgr, float elapsedTime)
{
	_sq.for_all([&](rnetwork::packet::MovePacket& e) {
		auto eid = e.getPlayerId();
		if (this->hasEntity(eid))
		{
			auto& pos = mgr.getEntityComponent<rtype::ct::Position>(eid);
			auto& vel = mgr.getEntityComponent<rtype::ct::Speed>(eid);

			auto const& pvel = e.getSpeed();
			auto const& ppos = e.getPosition();
			vel.x = pvel.x;
			vel.y = pvel.y;
			pos.x = ppos.x;
			pos.y = ppos.y;

			std::clog << " [INFO] [ Packet | Move ] :: From entity " << eid
				<< " | [" << ppos.x << ", " << ppos.y << "] |"
				<< " [" << pvel.x << ", " << pvel.y << "]" << std::endl;
		}
	});
}

rtypeserver::UpdateMove::UpdateMove(rnetwork::shared_queue<rnetwork::packet::MovePacket>& packets) :
_sq(packets)
{
	setRequiredComponents( { ecs::componentType<rtype::ct::Position>(),
							 ecs::componentType<rtype::ct::Speed>() });
}
