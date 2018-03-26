#include "LobbyListPacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::LobbyListPacket::LobbyListPacket() :
        PacketBase(op::LobbyListPacket, this->Size) {}

rnetwork::packet::LobbyListPacket::LobbyListPacket(const rnetwork::packet::PacketBase &base) :
        PacketBase(base) {}
