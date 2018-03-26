#include "LobbyJoinPacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::LobbyJoinPacket::LobbyJoinPacket(uint16_t id) :
        PacketBase(op::LobbyJoinPacket, this->Size)
{
    setId(id);
}

rnetwork::packet::LobbyJoinPacket::LobbyJoinPacket(const rnetwork::packet::PacketBase &base) : PacketBase(base) {}

void rnetwork::packet::LobbyJoinPacket::setId(uint16_t id) {
    auto *idPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    *idPtr = htons(id);
}

uint16_t rnetwork::packet::LobbyJoinPacket::getId() const {
    auto *idPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    return ntohs(*idPtr);
}
