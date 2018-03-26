#include <iostream>
#include <rnetwork/packet/StringPacket.hpp>
#include <rnetwork/tcp/Client.hpp>
#include <rnetwork/udp/Client.hpp>
#include "rnetwork/services/ExecService.hpp"
#include "rnetwork/tasks/ExecTask.hpp"
#include "rnetwork/packet/PacketBase.hpp"

static void receive_udp(std::shared_ptr<rnetwork::udp::Client> client, rnetwork::packet::PacketBase &packet, bool status)
{
    rnetwork::packet::StringPacket stringPacket("");

    std::cout << "Received status " << status << std::endl;
    if (status) {
        packet >> stringPacket;
        std::cout << stringPacket.str() << std::endl;
    }
    client->async_receive(std::bind(receive_udp, client, std::placeholders::_1, std::placeholders::_2));
}

static void receive_tcp(std::shared_ptr<rnetwork::tcp::Client> client, rnetwork::packet::PacketBase &packet, bool status)
{
    rnetwork::packet::StringPacket stringPacket("");

    std::cout << "Received status " << status << std::endl;
    if (status) {
        packet >> stringPacket;
        std::cout << stringPacket.str() << std::endl;
    }
    client->async_receive(std::bind(receive_tcp, client, std::placeholders::_1, std::placeholders::_2));
}

int main(int argc, const char **argv)
{
    if (argc < 3)
        return 1;

    rnetwork::init();
    rnetwork::async::IOService ioService;
    rnetwork::Endpoint endpoint(argv[1], static_cast<uint16_t>(std::atoi(argv[2])));
    rnetwork::packet::StringPacket packet("Hello World");

    /****************
    ** UDP Exemples *
    ****************/
    //auto client = std::make_shared<rnetwork::udp::Client>(endpoint, ioService);

    //client->async_send(packet, [&](bool status) {
    //    std::cout << "Send status " << std::boolalpha << status << std::endl;
    //});

    //client->async_receive(std::bind(receive_udp, client, std::placeholders::_1, std::placeholders::_2));

    auto client = std::make_shared<rnetwork::tcp::Client>(ioService, endpoint);

    client->async_send(packet, [&](bool status) {
        std::cout << "Send status " << std::boolalpha << status << std::endl;
    });

    client->async_receive(std::bind(receive_tcp, client, std::placeholders::_1, std::placeholders::_2));

    ioService.run();
    rnetwork::clean();
    return 0;
}
