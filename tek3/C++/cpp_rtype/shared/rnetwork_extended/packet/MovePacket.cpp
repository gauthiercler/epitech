//
// MovePacket.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/MovePacket.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  sam. janv. 20 05:49:51 2018 Anthony LECLERC
// Last update sam. janv. 20 05:49:51 2018 Anthony LECLERC
//

#include <utils/htonll.hpp>
#include "MovePacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::MovePacket::MovePacket(rnetwork::packet::PacketBase const& p)
	: PacketBase(p)
{}

rnetwork::packet::MovePacket::MovePacket(uint32_t e, rtype::ct::Position const& p, rtype::ct::Speed const& s) :
	PacketBase(op::MovePacket, Size)
{
	setPlayerId(e);
	setPosition(p);
	setSpeed(s);
}

rnetwork::packet::MovePacket::MovePacket() :
        PacketBase(op::MovePacket, Size) {}

uint32_t rnetwork::packet::MovePacket::getPlayerId() const
{
	auto *e = reinterpret_cast<uint32_t *>(&_raw[PlayerIdOffset]);
	return ntohl(*e);

}

void rnetwork::packet::MovePacket::setPlayerId(uint32_t e)
{
	auto *p = reinterpret_cast<uint32_t *>(&_raw[PlayerIdOffset]);
	*p = htonl(e);
}

rtype::ct::Position rnetwork::packet::MovePacket::getPosition() const
{
	auto velx (reinterpret_cast<uint32_t *>(&_raw[PositionOffset]));
	auto vely (reinterpret_cast<uint32_t *>(&_raw[PositionOffset] + sizeof(float)));

	return rtype::ct::Position(ntohl(*velx), ntohl(*vely));
}

rtype::ct::Speed rnetwork::packet::MovePacket::getSpeed() const
{
	auto velx (reinterpret_cast<uint32_t *>(&_raw[SpeedOffset]));
	auto vely (reinterpret_cast<uint32_t *>(&_raw[SpeedOffset] + sizeof(float)));

	return rtype::ct::Speed(ntohl(*velx), ntohl(*vely));
}

void
rnetwork::packet::MovePacket::setPosition(rtype::ct::Position const& p) const
{
	auto posx (reinterpret_cast<float *>(&_raw[SpeedOffset]));
	auto posy (reinterpret_cast<float *>(&_raw[SpeedOffset] + sizeof(float)));

	*posx = htonl(p.x);
	*posy = htonl(p.y);
}

void
rnetwork::packet::MovePacket::setSpeed(rtype::ct::Speed const& s) const
{
	auto velx (reinterpret_cast<float *>(&_raw[SpeedOffset]));
	auto vely (reinterpret_cast<float *>(&_raw[SpeedOffset] + sizeof(float)));

	*velx = htonl(s.x);
	*vely = htonl(s.y);
}


