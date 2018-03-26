#include "PlayerJoinedPacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::PlayerJoinedPacket::PlayerJoinedPacket(uint16_t id) :
        PacketBase(op::PlayerJoinedPacket, Size)
{
    setId(id);
}

rnetwork::packet::PlayerJoinedPacket::PlayerJoinedPacket(const rnetwork::packet::PacketBase &base) :
        PacketBase(base) {}

void rnetwork::packet::PlayerJoinedPacket::setId(uint16_t id) {
    auto *idPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    *idPtr = ntohs(id);
}

uint16_t rnetwork::packet::PlayerJoinedPacket::getId() const {
    auto *idPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    return ntohs(*idPtr);
}
