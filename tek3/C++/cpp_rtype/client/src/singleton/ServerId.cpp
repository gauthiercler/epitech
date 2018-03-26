//
// ServerId.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/ServerId.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  dim. janv. 21 09:47:51 2018 Anthony LECLERC
// Last update dim. janv. 21 09:47:51 2018 Anthony LECLERC
//

#include "singleton/ServerId.hpp"

void rtype::ServerId::associateId(
	ecs::Entity const serverId,
	ecs::Entity clientId) noexcept
{
	_fromClient.insert( { clientId , serverId });
	_fromServer.insert( { serverId , clientId});
}

ecs::Entity rtype::ServerId::fromServerId(ecs::Entity id)
{
	return _fromServer[id];
}

ecs::Entity rtype::ServerId::fromClientId(ecs::Entity id)
{
	return _fromClient[id];
}

void rtype::ServerId::remove(ecs::Entity const serverId)
{
	auto c = _fromServer[serverId];
	_fromClient.erase(c);
	_fromServer.erase(serverId);
}

void rtype::ServerId::clear() noexcept
{
	_fromClient.clear();
	_fromServer.clear();
}