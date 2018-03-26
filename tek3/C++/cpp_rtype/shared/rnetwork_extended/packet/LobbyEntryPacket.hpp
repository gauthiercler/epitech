#ifndef CPP_RTYPE_LOBBYENTRYPACKET_HPP
#define CPP_RTYPE_LOBBYENTRYPACKET_HPP

#include <rnetwork/packet/PacketBase.hpp>
#include "shared/rnetwork/config/Export.hpp"

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API LobbyEntryPacket : public PacketBase
        {
        private:

        public:
            static constexpr const std::size_t Size = 4;

            LobbyEntryPacket(uint16_t id = 0, uint16_t nbPlayers = 0);
            LobbyEntryPacket(const PacketBase &packetBase);
            LobbyEntryPacket(const LobbyEntryPacket &lobbyEntryPacket) = default;
            ~LobbyEntryPacket() override = default;

            void setId(uint16_t id);
            uint16_t getId() const;

            void setPlayersNb(uint16_t nb);
            uint16_t getPlayersNb() const;

            LobbyEntryPacket &operator=(const LobbyEntryPacket &lobbyEntryPacket) = default;
        };
    }
}


#endif //CPP_RTYPE_LOBBYENTRYPACKET_HPP
