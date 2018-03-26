#ifndef CPP_RTYPE_JOINGAME_HPP
#define CPP_RTYPE_JOINGAME_HPP

#include <rnetwork/packet/PacketBase.hpp>
#include "shared/rnetwork/config/Export.hpp"

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API JoinGamePacket : public rnetwork::packet::PacketBase
        {
        private:

        public:
            static constexpr const std::size_t Size = 2;

            JoinGamePacket(uint16_t id = 0);
            JoinGamePacket(PacketBase const& p);
            JoinGamePacket(const JoinGamePacket &joinGame) = default;
            ~JoinGamePacket() override = default;

            void setId(uint16_t id);
            uint16_t getId() const;

            JoinGamePacket &operator=(const JoinGamePacket &joinGame) = default;
        };
    }
}


#endif //CPP_RTYPE_JOINGAME_HPP
