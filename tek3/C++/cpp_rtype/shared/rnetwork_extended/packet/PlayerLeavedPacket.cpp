#include "PlayerLeavedPacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::PlayerLeavedPacket::PlayerLeavedPacket(uint16_t id) :
        PacketBase(op::PlayerLeavedPacket, Size) {
    setId(id);
}

rnetwork::packet::PlayerLeavedPacket::PlayerLeavedPacket(const rnetwork::packet::PacketBase &base) :
        PacketBase(base) {}

void rnetwork::packet::PlayerLeavedPacket::setId(uint16_t id) {
    auto *idPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    *idPtr = htons(id);
}

uint16_t rnetwork::packet::PlayerLeavedPacket::getId() const {
    auto *idPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    return ntohs(*idPtr);
}
