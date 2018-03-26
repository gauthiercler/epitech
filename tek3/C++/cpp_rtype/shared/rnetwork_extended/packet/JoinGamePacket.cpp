#include "JoinGamePacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::JoinGamePacket::JoinGamePacket(uint16_t id) :
        PacketBase(op::JoinGamePacket, this->Size)
{
    setId(id);
}

void rnetwork::packet::JoinGamePacket::setId(uint16_t id) {
    auto *idPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    *idPtr = htons(id);
}

uint16_t rnetwork::packet::JoinGamePacket::getId() const {
    auto *idPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    return ntohs(*idPtr);
}

rnetwork::packet::JoinGamePacket::JoinGamePacket(rnetwork::packet::PacketBase const& p)
	: PacketBase(p)
{}
