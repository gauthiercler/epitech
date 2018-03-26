#ifndef CPP_RTYPE_PLAYERIDPACKET_HPP
#define CPP_RTYPE_PLAYERIDPACKET_HPP

#include <rnetwork/packet/PacketBase.hpp>

namespace rnetwork
{
    namespace packet
    {
        class PlayerIdPacket : public PacketBase
        {
        private:

        public:
            static constexpr const std::size_t Size = 2;

            PlayerIdPacket(uint16_t id = 0);
            PlayerIdPacket(const PlayerIdPacket &playerIdPacket) = default;
            ~PlayerIdPacket() override = default;

            void setId(uint16_t id);
            uint16_t getId() const;

            PlayerIdPacket &operator=(const PlayerIdPacket &playerIdPacket) = default;
        };
    }
}


#endif //CPP_RTYPE_PLAYERIDPACKET_HPP
