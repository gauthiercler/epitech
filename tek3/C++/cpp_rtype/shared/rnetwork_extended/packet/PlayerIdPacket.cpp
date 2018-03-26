#include "PlayerIdPacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::PlayerIdPacket::PlayerIdPacket(uint16_t id) :
        PacketBase(op::PlayerIdPacket, this->Size)
{
    setId(id);
}

void rnetwork::packet::PlayerIdPacket::setId(uint16_t id) {
    auto *idPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    *idPtr = htons(id);
}

uint16_t rnetwork::packet::PlayerIdPacket::getId() const {
    auto *idPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    return ntohs(*idPtr);
}
