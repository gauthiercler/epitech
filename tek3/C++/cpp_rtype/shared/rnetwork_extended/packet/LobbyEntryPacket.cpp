#include "LobbyEntryPacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::LobbyEntryPacket::LobbyEntryPacket(uint16_t id, uint16_t nbPlayers) :
        PacketBase(op::LobbyEntryPacket, this->Size)
{
    setId(id);
    setPlayersNb(nbPlayers);
}

rnetwork::packet::LobbyEntryPacket::LobbyEntryPacket(const rnetwork::packet::PacketBase &packetBase) :
        PacketBase(packetBase) {}

void rnetwork::packet::LobbyEntryPacket::setId(uint16_t id) {
    auto *idPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    *idPtr = htons(id);
}

uint16_t rnetwork::packet::LobbyEntryPacket::getId() const {
    auto *idPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    return ntohs(*idPtr);
}

void rnetwork::packet::LobbyEntryPacket::setPlayersNb(uint16_t nb) {
    auto *playersNbPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE + 2]);
    *playersNbPtr = htons(nb);
}

uint16_t rnetwork::packet::LobbyEntryPacket::getPlayersNb() const {
    auto playerNbPtr = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE + 2]);
    return ntohs(*playerNbPtr);
}
