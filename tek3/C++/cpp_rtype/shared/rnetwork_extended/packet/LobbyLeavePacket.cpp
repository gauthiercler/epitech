#include "LobbyLeavePacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::LobbyLeavePacket::LobbyLeavePacket() :
        PacketBase(op::LobbyLeavePacket, Size) {}

rnetwork::packet::LobbyLeavePacket::LobbyLeavePacket(const rnetwork::packet::PacketBase &base) :
        PacketBase(base) {}
