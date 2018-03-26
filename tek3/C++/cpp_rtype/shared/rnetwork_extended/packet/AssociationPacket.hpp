#ifndef CPP_RTYPE_ASSOCIATIONPACKET_HPP
#define CPP_RTYPE_ASSOCIATIONPACKET_HPP

#include "rnetwork/packet/PacketBase.hpp"

namespace rnetwork
{
    namespace packet
    {
        class AssociationPacket : public rnetwork::packet::PacketBase
        {
        private:

        public:
            static constexpr const std::size_t Size = 0;

            AssociationPacket();
            AssociationPacket(const AssociationPacket &associationPacket) = default;
            ~AssociationPacket() override = default;

            AssociationPacket &operator=(const AssociationPacket &associationPacket) = default;
        };
    }
}


#endif //CPP_RTYPE_ASSOCIATIONPACKET_HPP
