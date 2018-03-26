#include <rnetwork/rnetwork.hpp>
#include <rnetwork/async/IOService.hpp>
#include <rnetwork/Endpoint.hpp>
#include <rnetwork/tcp/Acceptor.hpp>
#include <packet/UDPTokenPacket.hpp>
#include <iostream>
#include <rnetwork/Router.hpp>
#include <packet/UDPHostPacket.hpp>
#include <rnetwork/udp/Server.hpp>
#include <ClientChannel.hpp>
#include <ClientMasterChannel.hpp>

rnetwork::Router<void (rnetwork::packet::PacketBase&, std::shared_ptr<rnetwork::IClient>&)> router;

static void receive_tcp(rnetwork::packet::PacketBase packet, rnetwork::ClientChannel &channel, bool status)
{
    if (status) {
        std::cout << "Received data " << packet.getOp() << std::endl;
    }
}

static void accept_tcp(std::shared_ptr<rnetwork::tcp::Acceptor> acceptor, std::shared_ptr<rnetwork::IClient> client, bool status)
{
    if (status) {
        auto clientChannel = std::make_shared<rnetwork::ClientChannel>(acceptor->ioService());
        clientChannel->handleHandshake(client, rnetwork::Endpoint("127.0.0.1", 4243));
        acceptor->async_accept(std::bind(accept_tcp, acceptor, std::placeholders::_1, std::placeholders::_2));
    }
}

int main(int argc, const char **argv) {
    if (argc < 3)
        return 1;

    rnetwork::init();
    rnetwork::async::IOService ioService;
    rnetwork::Endpoint endpoint(argv[1], std::atoi(argv[2]));
    rnetwork::Endpoint endpointUdp(argv[1], std::atoi(argv[2]) + 1);

    auto clientMasterChannel = std::make_shared<rnetwork::ClientMasterChannel>(ioService, endpoint, endpointUdp);

    clientMasterChannel->setGateway([&](std::shared_ptr<rnetwork::ClientChannel> client, rnetwork::packet::PacketBase &packet) {
        std::cout << "Received " << packet.getOp() << std::endl;
        client->udpSend(packet);
    });
    clientMasterChannel->start();

    ioService.run();

    return 0;
}