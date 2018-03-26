#include "CreateLobbyPacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::CreateLobbyPacket::CreateLobbyPacket() :
        PacketBase(op::CreateLobbyPacket, this->Size) {}

rnetwork::packet::CreateLobbyPacket::CreateLobbyPacket(const rnetwork::packet::PacketBase &packet) :
        PacketBase(packet) {}
