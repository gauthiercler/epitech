#pragma once

#include <memory>
#include <functional>
#include "config/Export.hpp"
#include "rnetwork/rnetwork.hpp"

namespace rnetwork
{
    namespace packet
    {
        class PacketBase;
    }
    class RNETWORK_API IReceiver
    {
    public:
        virtual ~IReceiver() {}
        virtual std::shared_ptr<rnetwork::packet::PacketBase> receive(bool &status) = 0;
        virtual std::shared_ptr<rnetwork::packet::PacketBase> receive() = 0;
        virtual void async_receive(const std::function<void (rnetwork::packet::PacketBase&, bool status)> &callback) = 0;
        virtual SOCKET socket() const = 0;
    };
}