#ifndef CPP_RTYPE_CLIENT_TCP_HPP
#define CPP_RTYPE_CLIENT_TCP_HPP

#include "rnetwork/rnetwork.hpp"
#include "rnetwork/IClient.hpp"
#include "config/Export.hpp"
#include "rnetwork/async/IOService.hpp"

namespace rnetwork
{
    namespace tcp
    {
        class RNETWORK_API Client : public rnetwork::IClient, public std::enable_shared_from_this<Client>
        {
        private:
            rnetwork::async::IOService  &_ioService;
            rnetwork::Endpoint _endpoint;
            SOCKET _socket;
            bool _connected = false;

        public:
            explicit Client(rnetwork::async::IOService &ioService);
            Client(rnetwork::async::IOService &ioService, SOCKET socket, SOCKADDR_IN *remote);
            explicit Client(rnetwork::async::IOService &ioService, const rnetwork::Endpoint &endpoint);
            Client(const Client &client) = delete;
            virtual ~Client();

            bool connect(const rnetwork::Endpoint &endpoint);

            bool send(packet::IPacket const& packet) const override;
            void async_send(packet::IPacket const& packet, const std::function<void(bool)>& callback) override;
            std::shared_ptr<rnetwork::packet::PacketBase> receive(bool &status) override;
            std::shared_ptr<rnetwork::packet::PacketBase> receive() override;
            void async_receive(const std::function<void (rnetwork::packet::PacketBase&, bool status)> &callback) override;

            const rnetwork::Endpoint &getEndpoint() const override;

            SOCKET socket() const override;

            Client &operator=(const Client &client) = delete;

        private:
            std::string getRemoteHost(SOCKADDR_IN *remote) const;
            uint16_t getRemotePort(SOCKADDR_IN *remote) const;
        };
    }
}


#endif //CPP_RTYPE_CLIENT_TCP_HPP
