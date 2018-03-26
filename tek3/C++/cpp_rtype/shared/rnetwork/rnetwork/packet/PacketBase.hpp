#ifndef CPP_RTYPE_PACKETBASE_HPP
#define CPP_RTYPE_PACKETBASE_HPP

#include "rnetwork/async/IOService.hpp"
#include "rnetwork/rnetwork.hpp"
#include "IPacket.hpp"
#include "StringPacket.hpp"

#define PACKET_LENGTH_SIZE 2
#define PACKET_OP_SIZE 2
#define HEADER_SIZE PACKET_LENGTH_SIZE + PACKET_OP_SIZE

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API PacketBase : public rnetwork::packet::IPacket
        {
        protected:
            std::size_t _size;
            unsigned char *_raw;
            rnetwork::Endpoint _from;
            SOCKADDR_IN _fromLowLevel;

        public:
            PacketBase(uint16_t op = 0, std::size_t length = 0);
            PacketBase(unsigned char *raw, std::size_t size);
            PacketBase(unsigned char *raw, std::size_t size, SOCKADDR_IN *from);
            PacketBase(const PacketBase &packetBase);
            PacketBase(PacketBase&& packetBase) noexcept;
            virtual ~PacketBase();

            const unsigned char *raw() const override;
            std::size_t size() const override;
            const rnetwork::Endpoint &from() const override;

            void setLength(uint16_t length);
            void setOp(uint16_t op);

            uint16_t getLength() const;
            uint16_t getOp() const;

            void setRemote(const rnetwork::Endpoint &remote);
            const rnetwork::Endpoint &getRemote() const;


            template <typename T>
            std::shared_ptr<T> generateClient(rnetwork::async::IOService &ioService) const;

            std::shared_ptr<IPacket> snapshot() const override;

            PacketBase &operator=(const PacketBase &packetBase);
            PacketBase &operator>>(StringPacket &stringPacket);
        };
    }
}

#include "PacketBase.tcc"


#endif //CPP_RTYPE_PACKETBASE_HPP
