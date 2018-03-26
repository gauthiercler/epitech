//
// Opcodes.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/Opcodes.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  dim. janv. 21 01:46:52 2018 Anthony LECLERC
// Last update dim. janv. 21 01:46:52 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_OPCODES_HPP
#define CPP_RTYPE_OPCODES_HPP

#include <cstdint>

namespace rnetwork {
	namespace packet {
		namespace op {

			constexpr const uint16_t EntitySpawn = 1;
			constexpr const uint16_t UdpTokenPacket = 3;
			constexpr const uint16_t AssociationPacket = 4;
			constexpr const uint16_t UdpHostPacket = 5;
			constexpr const uint16_t JoinGamePacket = 6;
			constexpr const uint16_t PlayerIdPacket = 7;
			constexpr const uint16_t LobbyListPacket = 8;
			constexpr const uint16_t LobbyEntryPacket = 9;
			constexpr const uint16_t CreateLobbyPacket = 10;
			constexpr const uint16_t LobbyJoinPacket = 11;
			constexpr const uint16_t StartGamePacket = 12;
			constexpr const uint16_t LobbyLeavePacket = 13;
			constexpr const uint16_t PlayerJoinedPacket = 14;
			constexpr const uint16_t PlayerLeavedPacket = 15;
			constexpr const uint16_t MovePacket = 20;
		}
	}
}


#endif //CPP_RTYPE_OPCODES_HPP
