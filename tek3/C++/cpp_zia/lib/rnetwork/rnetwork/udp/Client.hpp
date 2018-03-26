#ifndef CPP_RTYPE_CLIENT_HPP
#define CPP_RTYPE_CLIENT_HPP

#include <string>
#include <memory>
#include "rnetwork/packet/PacketBase.hpp"
#include "rnetwork/rnetwork.hpp"
#include "rnetwork/Endpoint.hpp"
#include "rnetwork/async/IOService.hpp"
#include "rnetwork/IClient.hpp"
#include "config/Export.hpp"

namespace rnetwork
{
    namespace udp
    {
        class RNETWORK_API Client : public IClient, public std::enable_shared_from_this<Client>
        {
        private:
            rnetwork::async::IOService &_ioService;
            SOCKET _socket;
            SOCKADDR_IN _remote;
            rnetwork::Endpoint _endpoint;

        public:
            explicit Client(const rnetwork::Endpoint &endpoint, rnetwork::async::IOService &ioService);
            Client(const SOCKADDR_IN *endpoint, rnetwork::async::IOService &ioService);
            Client(const Client &client);
            virtual ~Client();

            bool send(rnetwork::packet::IPacket const& packet) const override;
            void async_send(rnetwork::packet::IPacket const& packet, const std::function<void (bool)> &callback) override;
            std::shared_ptr<rnetwork::packet::PacketBase> receive(bool &status) override;
            std::shared_ptr<rnetwork::packet::PacketBase> receive() override;
            void async_receive(const std::function<void (rnetwork::packet::PacketBase&, bool status)> &callback) override;

            SOCKET socket() const override;

            const rnetwork::Endpoint &getEndpoint() const override;


            Client &operator=(const Client &client);
        private:
            void _link(const rnetwork::Endpoint &endpoint);
        };

    }
}


#endif //CPP_RTYPE_CLIENT_HPP
