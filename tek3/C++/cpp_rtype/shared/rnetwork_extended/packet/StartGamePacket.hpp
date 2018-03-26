#ifndef CPP_RTYPE_STARTGAMEPACKET_HPP
#define CPP_RTYPE_STARTGAMEPACKET_HPP

#include <rnetwork/packet/PacketBase.hpp>
#include "shared/rnetwork/config/Export.hpp"

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API StartGamePacket : public PacketBase
        {
        private:

        public:
            static constexpr const std::size_t Size = 0;

            StartGamePacket();
            StartGamePacket(const PacketBase &base);
            StartGamePacket(const StartGamePacket &startGamePacket) = default;
            ~StartGamePacket() override = default;

            StartGamePacket &operator=(const StartGamePacket &startGamePacket) = default;
        };
    }
}


#endif //CPP_RTYPE_STARTGAMEPACKET_HPP
