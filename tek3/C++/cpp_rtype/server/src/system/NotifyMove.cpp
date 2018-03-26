//
// NotifyMove.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/NotifyMove.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  dim. janv. 21 11:21:39 2018 Anthony LECLERC
// Last update dim. janv. 21 11:21:39 2018 Anthony LECLERC
//

#include <Speed.hpp>
#include <packet/MovePacket.hpp>
#include "Manager.hpp"
#include "server/include/system/NotifyMove.hpp"

void rtypeserver::NotifyMove::process(ecs::Manager& mgr, float elapsedTime)
{
	for (auto&& entity : entities)
	{
		auto const& pos = mgr.getEntityComponent<rtype::ct::Position>(entity);
		auto const& vel = mgr.getEntityComponent<rtype::ct::Speed>(entity);

		rnetwork::packet::MovePacket m(static_cast<uint32_t>(entity), pos, vel);
		for (auto&& client : _players)
		{
			client->send(m);
		}
	}
}

rtypeserver::NotifyMove::NotifyMove(std::vector<std::shared_ptr<rtypeserver::Player>>& players) :
_players(players)
{
	setRequiredComponents( { ecs::componentType<rtype::ct::Position>(),
						   ecs::componentType<rtype::ct::Speed>() } );
}
