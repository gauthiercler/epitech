#ifndef CPP_RTYPE_PLAYERJOINEDPACKET_HPP
#define CPP_RTYPE_PLAYERJOINEDPACKET_HPP

#include <rnetwork/packet/PacketBase.hpp>
#include "config/Export.hpp"

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API PlayerJoinedPacket : public PacketBase
        {
        private:

        public:
            static constexpr const std::size_t Size = 2;

            PlayerJoinedPacket(uint16_t id = 0);
            PlayerJoinedPacket(const PacketBase &base);
            PlayerJoinedPacket(const PlayerJoinedPacket &playerJoinedPacket) = default;
            ~PlayerJoinedPacket() override = default;

            void setId(uint16_t id);
            uint16_t getId() const;

            PlayerJoinedPacket &operator=(const PlayerJoinedPacket &playerJoinedPacket) = default;
        };
    }
}


#endif //CPP_RTYPE_PLAYERJOINEDPACKET_HPP
