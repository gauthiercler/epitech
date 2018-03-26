#pragma once

#include "rnetwork/packet/IPacket.hpp"
#include "config/Export.hpp"

namespace rnetwork
{
    class RNETWORK_API ISender
    {
    public:
        virtual bool send(rnetwork::packet::IPacket const& packet) const = 0;
        virtual void async_send(rnetwork::packet::IPacket const& packet, const std::function<void (bool)> &callback) = 0;
        virtual SOCKET socket() const = 0;
    };
}