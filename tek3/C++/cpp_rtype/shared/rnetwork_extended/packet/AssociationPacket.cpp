#include "AssociationPacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::AssociationPacket::AssociationPacket() :
        PacketBase(op::AssociationPacket, this->Size)
{}
