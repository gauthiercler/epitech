#pragma once

#include <memory>
#include "IClient.hpp"
#include "config/Export.hpp"

namespace rnetwork
{
    class RNETWORK_API IAcceptor
    {
    public:
        virtual std::shared_ptr<rnetwork::IClient> accept(bool &status) const = 0;
        virtual std::shared_ptr<rnetwork::IClient> accept() const = 0;
        virtual void async_accept(const std::function<void (std::shared_ptr<rnetwork::IClient> client, bool status)> &callback) = 0;
        virtual SOCKET socket() const = 0;
    };
}