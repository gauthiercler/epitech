#ifndef CPP_RTYPE_STRINGPACKET_HPP
#define CPP_RTYPE_STRINGPACKET_HPP

#include <string>
#include "config/Export.hpp"
#include "IPacket.hpp"

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API StringPacket : public IPacket
        {
        private:
            std::string _data;
            rnetwork::Endpoint _from;

        public:
            explicit StringPacket(const std::string &string);
            StringPacket(const StringPacket &stringPacket) = default;
            virtual ~StringPacket() = default;

            const std::string &str() const;

            std::size_t size() const override;
            const unsigned char *raw() const override;
            const rnetwork::Endpoint &from() const override;

            std::shared_ptr<IPacket> snapshot() const override;

            StringPacket &operator=(const StringPacket &stringPacket) = default;
        };
    }
}

RNETWORK_API std::ostream &operator<<(std::ostream &os, const rnetwork::packet::StringPacket &packet);


#endif //CPP_RTYPE_STRINGPACKET_HPP
