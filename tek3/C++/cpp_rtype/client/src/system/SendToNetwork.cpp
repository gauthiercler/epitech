//
// SendToNetwork.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/SendToNetwork.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  sam. janv. 20 06:32:58 2018 Anthony LECLERC
// Last update sam. janv. 20 06:32:58 2018 Anthony LECLERC
//

#include <Position.hpp>
#include <component/types/ComponentIdGenerator.hpp>
#include <RtypeCommand.hpp>
#include <packet/MovePacket.hpp>
#include <client/include/singleton/ServerId.hpp>
#include "client/include/system/SendToNetwork.hpp"
#include "Manager.hpp"

void rtype::SendToNetwork::process(ecs::Manager& mgr, float elapsed_time)
{
	for (auto&& entity : entities) {

		auto const& input = mgr.getEntityComponent<ct::RtypeCommand>(entity);
		if (input.triggered)
		{
			auto const& pos = mgr.getEntityComponent<ct::Position>(entity);
			auto const& vel = mgr.getEntityComponent<ct::Speed>(entity);
			auto sId = Singleton<ServerId>::get().fromClientId(entity);
			if (!_client->udpSend(rnetwork::packet::MovePacket(sId, pos, vel)))
				std::clog << " [NET | ERROR] :: Sending command MOVE to server." << std::endl;
			else
				std::clog << " [ NET ] :: Sending command MOVE to server." << std::endl;
		}
	}
}

rtype::SendToNetwork::SendToNetwork(std::shared_ptr<rnetwork::ClientChannel> const& channel) :
	_client(channel)
{
	setRequiredComponents( { ecs::componentType<ct::RtypeCommand>(),
						   ecs::componentType<ct::Position>(),
						   ecs::componentType<ct::Speed>() } );
}
