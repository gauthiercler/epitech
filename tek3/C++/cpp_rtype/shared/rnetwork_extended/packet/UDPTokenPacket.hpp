#ifndef CPP_RTYPE_UDPTOKEN_HPP
#define CPP_RTYPE_UDPTOKEN_HPP

#include <rnetwork/packet/PacketBase.hpp>
#include "config/Export.hpp"
#include "rnetwork/packet/IPacket.hpp"

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API UDPTokenPacket : public rnetwork::packet::PacketBase
        {
        private:
            std::string _token;

        public:
            static constexpr const std::size_t Size = 4;
			static constexpr const std::size_t TokenSize = Size;
            UDPTokenPacket();
            UDPTokenPacket(const std::string &token);
            UDPTokenPacket(const rnetwork::packet::PacketBase &packet);
            ~UDPTokenPacket() override = default;

            void setToken(const std::string &token);
            const std::string &getToken() const;

            std::shared_ptr<IPacket> snapshot() const override;

            UDPTokenPacket &operator=(const UDPTokenPacket &packet);
        };

    }
}

RNETWORK_API rnetwork::packet::PacketBase &operator>>(rnetwork::packet::PacketBase &base, rnetwork::packet::UDPTokenPacket &packet);


#endif //CPP_RTYPE_UDPTOKEN_HPP
