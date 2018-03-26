#include <iostream>
#include "rnetwork/udp/Client.hpp"
#include "rnetwork/tcp/Acceptor.hpp"
#include "rnetwork/udp/Server.hpp"

static void receive(std::shared_ptr<rnetwork::udp::Server> &server, rnetwork::packet::PacketBase &packet, bool status)
{
    rnetwork::packet::StringPacket stringPacket("");

    if (status) {
        packet >> stringPacket;
        std::cout << "Received " << stringPacket.str() << std::endl;
        auto client = packet.generateClient<rnetwork::udp::Client>(server->ioService());
        client->async_send(packet, [&](bool status) {
            std::cout << "Resent packet " << status << std::endl;
        });
    }
    server->async_receive(std::bind(receive, server, std::placeholders::_1, std::placeholders::_2));
}

static void receive_tcp(std::shared_ptr<rnetwork::IClient> client, rnetwork::packet::PacketBase &packet, bool status)
{
    if (status) {
        rnetwork::packet::StringPacket string("");
        packet >> string;
        std::cout << "Received " << string << std::endl;
        client->async_receive(std::bind(receive_tcp, client, std::placeholders::_1, std::placeholders::_2));
    } else
        std::cout << "Client disconnected" << std::endl;
}

static void accept_tcp(std::shared_ptr<rnetwork::IAcceptor> acceptor, std::shared_ptr<rnetwork::IClient> client, bool status)
{
    std::cout << "Accept new client, status: " << status << std::endl;
    if (status) {
        client->async_receive(std::bind(receive_tcp, client, std::placeholders::_1, std::placeholders::_2));
        acceptor->async_accept(std::bind(accept_tcp, acceptor, std::placeholders::_1, std::placeholders::_2));
    }
}

int main(int argc, const char **argv)
{
    if (argc < 3)
        return 1;

    rnetwork::init();
    rnetwork::async::IOService ioService;
    rnetwork::Endpoint endpoint(argv[1], std::atoi(argv[2]));

    /*****************
    ** UDP Exemples **
    *****************/
    //auto server = std::make_shared<rnetwork::udp::Server>(ioService, endpoint);

    //server->async_receive(std::bind(receive, server, std::placeholders::_1, std::placeholders::_2));

    auto acceptor = std::make_shared<rnetwork::tcp::Acceptor>(ioService, endpoint, 10);

    acceptor->async_accept(std::bind(accept_tcp, acceptor, std::placeholders::_1, std::placeholders::_2));

    ioService.run();

    return 0;
}