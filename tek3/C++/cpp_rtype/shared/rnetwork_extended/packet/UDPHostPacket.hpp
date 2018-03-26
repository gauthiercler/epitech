#ifndef CPP_RTYPE_UDPHOSTPACKET_HPP
#define CPP_RTYPE_UDPHOSTPACKET_HPP

#include <rnetwork/packet/PacketBase.hpp>

namespace rnetwork
{
    namespace packet
    {
        class UDPHostPacket : public rnetwork::packet::PacketBase
        {
        private:
            rnetwork::Endpoint _endpoint;

        public:
            static constexpr const std::size_t Size = 2;

            UDPHostPacket();
            UDPHostPacket(const rnetwork::packet::PacketBase &base);
            UDPHostPacket(const rnetwork::Endpoint &endpoint);
            UDPHostPacket(const UDPHostPacket &udpHostPacket) = default;
            ~UDPHostPacket() override = default;

            void setEndpoint(const rnetwork::Endpoint &endpoint);
            const rnetwork::Endpoint &getEndpoint() const;

            UDPHostPacket &operator=(const UDPHostPacket &udpHostPacket) = default;
        private:
            void updatePacket();
            std::string getRawHost() const;
            uint16_t getRawPort() const;
        };
    }
}


#endif //CPP_RTYPE_UDPHOSTPACKET_HPP
