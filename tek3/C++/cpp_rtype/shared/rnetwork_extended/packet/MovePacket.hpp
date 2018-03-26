//
// MovePacket.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/MovePacket.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  sam. janv. 20 05:49:51 2018 Anthony LECLERC
// Last update sam. janv. 20 05:49:51 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_PLAYERMOVEPACKET_HPP
#define CPP_RTYPE_PLAYERMOVEPACKET_HPP

#include <rnetwork/packet/PacketBase.hpp>
#include <component/types/ComponentIdGenerator.hpp>
#include <Speed.hpp>
#include <Entity.hpp>
#include <Position.hpp>

namespace rnetwork {
	namespace packet {

		class RNETWORK_API MovePacket : public PacketBase {
		public:
			static constexpr const std::size_t PlayerIdOffset = HEADER_SIZE;
			static constexpr const std::size_t PositionOffset = PlayerIdOffset + sizeof(uint32_t);
			static constexpr const std::size_t SpeedOffset = PositionOffset + sizeof(uint32_t) * 2;
			static constexpr const std::size_t Size = (SpeedOffset + sizeof(uint32_t) * 2) - HEADER_SIZE;

			MovePacket();
			MovePacket(uint32_t e,
					   rtype::ct::Position const& p,
					   rtype::ct::Speed const& s);
			MovePacket(PacketBase const&);
			MovePacket(MovePacket const&) = default;
			virtual ~MovePacket() = default;

			uint32_t getPlayerId() const;

			rtype::ct::Position getPosition() const;

			rtype::ct::Speed getSpeed() const;

			void setPlayerId(uint32_t e);

			void setPosition(rtype::ct::Position const& p) const;

			void setSpeed(rtype::ct::Speed const& s) const;
		private:
		};
	}
}


#endif //CPP_RTYPE_PLAYERMOVEPACKET_HPP
