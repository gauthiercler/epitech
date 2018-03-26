#ifndef CPP_RTYPE_CEATELOBBYPACKET_HPP
#define CPP_RTYPE_CEATELOBBYPACKET_HPP

#include <rnetwork/packet/PacketBase.hpp>
#include "shared/rnetwork/config/Export.hpp"

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API CreateLobbyPacket : public PacketBase
        {
        private:

        public:
            static constexpr const std::size_t Size = 0;

            CreateLobbyPacket();
            CreateLobbyPacket(const CreateLobbyPacket &createLobbyPacket) = default;
            CreateLobbyPacket(const PacketBase &packet);
            ~CreateLobbyPacket() override = default;

            CreateLobbyPacket &operator=(const CreateLobbyPacket &createLobbyPacket) = default;
        };
    }
}


#endif //CPP_RTYPE_CEATELOBBYPACKET_HPP
