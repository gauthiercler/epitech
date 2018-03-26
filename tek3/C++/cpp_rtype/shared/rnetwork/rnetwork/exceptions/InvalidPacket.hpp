#ifndef CPP_RTYPE_INVALIDPACKET_HPP
#define CPP_RTYPE_INVALIDPACKET_HPP

#include <stdexcept>

namespace rnetwork
{
    namespace exceptions
    {
        class InvalidPacket : public std::runtime_error
        {
        private:

        public:
            InvalidPacket(const std::string &what);
            InvalidPacket(const InvalidPacket &packet) = default;
            virtual ~InvalidPacket() = default;

            InvalidPacket &operator=(const InvalidPacket &packet) = default;
        };
    }
}


#endif //CPP_RTYPE_INVALIDPACKET_HPP
