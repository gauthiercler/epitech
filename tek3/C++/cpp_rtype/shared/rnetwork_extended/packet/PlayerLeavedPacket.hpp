#ifndef CPP_RTYPE_PLAYERLEAVEDPACKET_HPP
#define CPP_RTYPE_PLAYERLEAVEDPACKET_HPP

#include <rnetwork/packet/PacketBase.hpp>
#include <config/Export.hpp>

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API PlayerLeavedPacket : public PacketBase
        {
        private:

        public:
            static constexpr const std::size_t Size = 2;

            PlayerLeavedPacket(uint16_t id = 0);
            PlayerLeavedPacket(const PacketBase &base);
            PlayerLeavedPacket(const PlayerLeavedPacket &playerLeavedPacket) = default;
            ~PlayerLeavedPacket() override = default;

            void setId(uint16_t id);
            uint16_t getId() const;

            PlayerLeavedPacket &operator=(const PlayerLeavedPacket &playerLeavedPacket) = default;
        };
    }
}


#endif //CPP_RTYPE_PLAYERLEAVEDPACKET_HPP
