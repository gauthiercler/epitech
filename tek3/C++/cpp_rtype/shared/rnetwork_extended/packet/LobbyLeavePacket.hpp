#ifndef CPP_RTYPE_LOBBYLEAVE_HPP
#define CPP_RTYPE_LOBBYLEAVE_HPP

#include <rnetwork/packet/PacketBase.hpp>
#include "config/Export.hpp"

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API LobbyLeavePacket : public PacketBase
        {
        private:

        public:
            static constexpr const std::size_t Size = 0;

            LobbyLeavePacket();
            LobbyLeavePacket(const PacketBase &base);
            LobbyLeavePacket(const LobbyLeavePacket &lobbyLeave) = default;
            ~LobbyLeavePacket() override = default;

            LobbyLeavePacket &operator=(const LobbyLeavePacket &lobbyLeave) = default;
        };
    }
}


#endif //CPP_RTYPE_LOBBYLEAVE_HPP
