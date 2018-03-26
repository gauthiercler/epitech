//
// ClientChannel.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/ClientChannel.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 17 14:34:45 2018 Anthony LECLERC
// Last update mer. janv. 17 14:34:45 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_CLIENTCHANNEL_HPP
#define CPP_RTYPE_CLIENTCHANNEL_HPP

#include "rnetwork/tcp/Client.hpp"
#include "rnetwork/udp/Client.hpp"
#include "rnetwork/Router.hpp"
#include "shared/rnetwork/config/Export.hpp"

namespace rnetwork {
    class RNETWORK_API ClientChannel : public std::enable_shared_from_this<ClientChannel>
    {
    private:
        rnetwork::async::IOService &_ioService;
        std::shared_ptr<IClient> _tcpClient;
        std::shared_ptr<IClient> _udpClient;
        rnetwork::Router<void (packet::PacketBase&, std::shared_ptr<IClient>) > _router;
        std::string _identifier;
        rnetwork::Endpoint _tcpEndpoint;
        rnetwork::Endpoint _udpEndpoint;
        std::function<void (std::shared_ptr<ClientChannel> channel, rnetwork::packet::PacketBase &)> _gateway;
        std::function<void (std::shared_ptr<ClientChannel> channel)> _disconnectCallback;
        bool _associated = false;

    public:
        explicit ClientChannel(rnetwork::async::IOService &ioService);
        ClientChannel(const rnetwork::ClientChannel &clientChannel) = default;
        virtual ~ClientChannel() = default;

        void handshake(const rnetwork::Endpoint &tcpEndpoint);
        void handleHandshake(std::shared_ptr<rnetwork::IClient> client, const rnetwork::Endpoint &udpEndpoint);
        void finalizeHandshake(std::shared_ptr<rnetwork::IClient> client);

        void setIdentifier(const std::string &identifier);
        const std::string &getIdentitfier() const;
        void generateIdentifier();

        void setGateway(const std::function<void (std::shared_ptr<ClientChannel> channel, rnetwork::packet::PacketBase &)> &gateway);
        void setDisconnectCallback(const std::function<void (std::shared_ptr<ClientChannel>)> &callback);

        bool isAssociated() const;
        void tcpSend(rnetwork::packet::IPacket const &packet) const;
        bool udpSend(rnetwork::packet::IPacket const &packet);

        bool is(const rnetwork::Endpoint &endpoint);
        std::shared_ptr<rnetwork::IClient> getClient(const rnetwork::Endpoint &endpoint);

        ClientChannel &operator=(const ClientChannel &clientChannel) = delete;

    private:
        void handlePacket(std::shared_ptr<rnetwork::IClient> receiver, rnetwork::packet::PacketBase &packet, bool status);
        void initRouter();
        void handleTokenPacket(rnetwork::packet::PacketBase &packet, std::shared_ptr<rnetwork::IClient> client);
        void handleHostPacket(rnetwork::packet::PacketBase &packet, std::shared_ptr<rnetwork::IClient> client);
        void handleAssociationPacket(rnetwork::packet::PacketBase &packet, std::shared_ptr<rnetwork::IClient> client);
        void sendUDPToken(const rnetwork::Endpoint &endpoint);
    };
}

#endif //CPP_RTYPE_CLIENTCHANNEL_HPP

