#include "StartGamePacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::StartGamePacket::StartGamePacket() :
        PacketBase(op::StartGamePacket, this->Size) {}

rnetwork::packet::StartGamePacket::StartGamePacket(const rnetwork::packet::PacketBase &base) :
        PacketBase(base) {}
