#pragma once

#include "rnetwork/IReceiver.hpp"
#include "rnetwork/ISender.hpp"
#include "config/Export.hpp"

namespace rnetwork
{
    class RNETWORK_API IClient : public rnetwork::ISender, public rnetwork::IReceiver
    {
    public:
        virtual const rnetwork::Endpoint &getEndpoint() const = 0;
    };
}