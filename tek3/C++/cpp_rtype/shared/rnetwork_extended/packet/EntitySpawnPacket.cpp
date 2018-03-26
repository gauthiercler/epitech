#include <Position.hpp>
#include <utils/htonll.hpp>
#include "EntitySpawnPacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::EntitySpawnPacket::EntitySpawnPacket() :
        PacketBase(op::EntitySpawn, this->Size) {
}

rnetwork::packet::EntitySpawnPacket::EntitySpawnPacket(uint32_t id, uint16_t type, rtype::ct::Position const& pos) :
        EntitySpawnPacket()
{
    setId(id);
    setType(type);
    setPos(pos);
}

void rnetwork::packet::EntitySpawnPacket::setId(uint32_t id) {
    auto *idPtr = reinterpret_cast<uint32_t *>(&_raw[idOffset]);
    *idPtr = htonl(id);
	std::cout << "[INFO | EntityPacket] Initial ID :: " << id << " | Network ID :: " << *idPtr <<
		" | Converted ID :: " << getId() << std::endl;
}

uint32_t rnetwork::packet::EntitySpawnPacket::getId() const {
    auto *idPtr = reinterpret_cast<uint32_t *>(&_raw[idOffset]);
    return ntohl(*idPtr);
}

void rnetwork::packet::EntitySpawnPacket::setType(uint16_t type) {
    auto *typePtr = reinterpret_cast<uint16_t *>(&_raw[typeOffset]);
    *typePtr = htons(type);
}

uint16_t rnetwork::packet::EntitySpawnPacket::getType() const {
    auto *typePtr = reinterpret_cast<uint16_t *>(&_raw[typeOffset]);
    return ntohs(*typePtr);
}

void rnetwork::packet::EntitySpawnPacket::setPos(rtype::ct::Position const& pos) {
    auto *x = reinterpret_cast<uint32_t *>(&_raw[posXOffset]);
    auto *y = reinterpret_cast<uint32_t *>(&_raw[posYOffset]);
    *x = htonl(static_cast<uint32_t>(pos.x));
    *y = htonl(static_cast<uint32_t>(pos.y));
}

rtype::ct::Position rnetwork::packet::EntitySpawnPacket::getpos() const {
    rtype::ct::Position pos{};
    auto *x = reinterpret_cast<uint32_t *>(&_raw[posXOffset]);
    auto *y = reinterpret_cast<uint32_t *>(&_raw[posYOffset]);

    pos.x = ntohl(*x);
    pos.y = ntohl(*y);
    return std::move(pos);
}

rnetwork::packet::EntitySpawnPacket::EntitySpawnPacket(rnetwork::packet::PacketBase const& p)
    : PacketBase(p)
{}
