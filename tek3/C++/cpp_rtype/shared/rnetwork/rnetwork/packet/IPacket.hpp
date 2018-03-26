#pragma once

#include <cstddef>
#include <memory>
#include "rnetwork/Endpoint.hpp"
#include "config/Export.hpp"

namespace rnetwork
{
    namespace packet
    {
        class RNETWORK_API IPacket
        {
        public:
            virtual std::size_t size() const = 0;
            virtual const unsigned char *raw() const = 0;
            virtual const rnetwork::Endpoint &from() const = 0;
            virtual std::shared_ptr<IPacket> snapshot() const = 0;
        };
    }
}