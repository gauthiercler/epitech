#ifndef CPP_RTYPE_CLIENTMASTERCHANNEL_HPP
#define CPP_RTYPE_CLIENTMASTERCHANNEL_HPP

#include <unordered_map>
#include <rnetwork/Endpoint.hpp>
#include <rnetwork/tcp/Acceptor.hpp>
#include <rnetwork/udp/Server.hpp>
#include "ClientChannel.hpp"
#include "shared/rnetwork/config/Export.hpp"

namespace rnetwork
{
    class RNETWORK_API ClientMasterChannel : public std::enable_shared_from_this<ClientMasterChannel>
    {
    private:
        std::unordered_map<std::string, std::shared_ptr<rnetwork::ClientChannel>> _clients;
        rnetwork::async::IOService &_ioService;
        std::shared_ptr<rnetwork::tcp::Acceptor> _tcpAcceptor;
        std::shared_ptr<rnetwork::udp::Server> _udpServer;
        rnetwork::Endpoint _udpEndpoint;
        rnetwork::Router<void (packet::PacketBase&, std::shared_ptr<IClient>) > _router;
        std::function<void (std::shared_ptr<ClientChannel> channel, rnetwork::packet::PacketBase &)> _gateway;
        std::function<void (std::shared_ptr<ClientChannel> channel)> _connection;
        std::function<void (std::shared_ptr<ClientChannel> channel)> _disconnection;

    public:
        ClientMasterChannel(rnetwork::async::IOService &ioService, const rnetwork::Endpoint &tpcEndpoint, const rnetwork::Endpoint &udpEndpoint);
        ClientMasterChannel(const ClientMasterChannel &clientMasterChannel) = default;
        virtual ~ClientMasterChannel() = default;

        void start();
        void setGateway(const std::function<void (std::shared_ptr<ClientChannel> channel, rnetwork::packet::PacketBase &)> &gateway);
        void setConnectionCallback(const std::function<void (std::shared_ptr<ClientChannel>)> &connectionCallback);
        void setDisconnectionCallback(const std::function<void (std::shared_ptr<ClientChannel>)> &disconnectionCallback);

        ClientMasterChannel &operator=(const ClientMasterChannel &clientMasterChannel) = delete;

    private:
        void initRouter();
        void handleConnection(std::shared_ptr<rnetwork::IClient> client, bool status);
        void handleDisconnection(std::shared_ptr<rnetwork::ClientChannel> client);
        void handlePacket(std::shared_ptr<rnetwork::IReceiver> client, rnetwork::packet::PacketBase &packet, bool status);
        void handleTokenId(rnetwork::packet::PacketBase &packet, std::shared_ptr<rnetwork::IClient> client);

        std::shared_ptr<rnetwork::IClient> getClient(const rnetwork::Endpoint &endpoint) const;
        std::shared_ptr<rnetwork::ClientChannel> getChannel(const rnetwork::Endpoint &endpoint) const;
        std::shared_ptr<rnetwork::ClientChannel> getChannel(const std::string &token) const;
    };
}


#endif //CPP_RTYPE_CLIENTMASTERCHANNEL_HPP
