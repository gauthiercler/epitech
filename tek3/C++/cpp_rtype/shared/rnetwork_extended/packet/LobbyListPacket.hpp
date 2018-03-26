#ifndef CPP_RTYPE_LOBBYLISTPACKET_HPP
#define CPP_RTYPE_LOBBYLISTPACKET_HPP

#include "rnetwork/packet/PacketBase.hpp"
#include "shared/rnetwork/config/Export.hpp"

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API LobbyListPacket : public PacketBase
        {
        private:

        public:
            static constexpr const std::size_t Size = 0;

            LobbyListPacket();
            LobbyListPacket(const PacketBase &base);
            LobbyListPacket(const LobbyListPacket &lobbyListPacket) = default;
            ~LobbyListPacket() override = default;

            LobbyListPacket &operator=(const LobbyListPacket &lobbyListPacket) = default;
        };
    }
}


#endif //CPP_RTYPE_LOBBYLISTPACKET_HPP
