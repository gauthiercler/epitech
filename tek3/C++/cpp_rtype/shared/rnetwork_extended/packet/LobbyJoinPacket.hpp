#ifndef CPP_RTYPE_LOBBYJOINPACKET_HPP
#define CPP_RTYPE_LOBBYJOINPACKET_HPP

#include <cstdint>
#include <rnetwork/packet/PacketBase.hpp>
#include "shared/rnetwork/config/Export.hpp"

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API LobbyJoinPacket : public PacketBase
        {
        private:

        public:
            static constexpr const std::size_t Size = 2;

            LobbyJoinPacket(uint16_t id = 0);
            LobbyJoinPacket(const PacketBase &base);
            LobbyJoinPacket(const LobbyJoinPacket &lobbyJoinPacket) = default;
            ~LobbyJoinPacket() override = default;

            void setId(uint16_t id);
            uint16_t getId() const;

            LobbyJoinPacket &operator=(const LobbyJoinPacket &lobbyJoinPacket) = default;
        };
    }
}


#endif //CPP_RTYPE_LOBBYJOINPACKET_HPP
