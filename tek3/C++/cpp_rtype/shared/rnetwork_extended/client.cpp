#include <iostream>
#include <ClientChannel.hpp>
#include <rnetwork/tasks/DelayedTask.hpp>
#include <packet/EntitySpawnPacket.hpp>
#include <packet/LobbyListPacket.hpp>
#include <packet/CreateLobbyPacket.hpp>
#include <packet/StartGamePacket.hpp>
#include <packet/LobbyEntryPacket.hpp>
#include <packet/LobbyJoinPacket.hpp>
#include "rnetwork/rnetwork.hpp"
#include "rnetwork/async/IOService.hpp"
#include "rnetwork/Endpoint.hpp"
#include "rnetwork/tcp/Client.hpp"
#include "rnetwork/Router.hpp"
#include "packet/Opcodes.hpp"
#include "packet/UDPTokenPacket.hpp"

static void startGame(rnetwork::packet::PacketBase &packet)
{
    std::cout << "Game started" << std::endl;
}

static void lobbyEntry(rnetwork::packet::PacketBase &packet)
{
    rnetwork::packet::LobbyEntryPacket entry(packet);
    std::cout << "Lobby " << entry.getId() << " have " << entry.getPlayersNb() << " players." << std::endl;
}

static void lobbyJoin(rnetwork::packet::PacketBase &packet)
{
    rnetwork::packet::LobbyJoinPacket lobby(packet);
    std::cout << "Joined lobby " << lobby.getId() << std::endl;
}

int main(int argc, const char **argv)
{
    if (argc < 3)
        return 1;

    rnetwork::init();
    rnetwork::async::IOService ioService;
    rnetwork::Endpoint endpoint(argv[1], static_cast<uint16_t>(std::atoi(argv[2])));
    rnetwork::Router<void(rnetwork::packet::PacketBase &)> router;

    router.registerRoute(rnetwork::packet::op::StartGamePacket, startGame);
    router.registerRoute(rnetwork::packet::op::LobbyEntryPacket, lobbyEntry);
    router.registerRoute(rnetwork::packet::op::LobbyJoinPacket, lobbyJoin);

    auto clientChannel = std::make_shared<rnetwork::ClientChannel>(ioService);

    clientChannel->setGateway([&](std::shared_ptr<rnetwork::ClientChannel> client, rnetwork::packet::PacketBase &packet) {
        if (router.isRegistered(packet.getOp()))
            router(packet);
        else
            std::cout << "drop packet " << packet.getOp() << std::endl;
    });
    clientChannel->handshake(endpoint);

    auto task = std::make_shared<rnetwork::tasks::DelayedTask>([&]() {
        rnetwork::packet::LobbyListPacket packet;
       clientChannel->tcpSend(packet);
    }, 2);
    auto task1 = std::make_shared<rnetwork::tasks::DelayedTask>([&]() {
        rnetwork::packet::CreateLobbyPacket packet;
        clientChannel->tcpSend(packet);
    }, 3);
    auto task2 = std::make_shared<rnetwork::tasks::DelayedTask>([&]() {
        rnetwork::packet::LobbyJoinPacket packet(0);
        clientChannel->tcpSend(packet);
    }, 3);
    auto task3 = std::make_shared<rnetwork::tasks::DelayedTask>([&]() {
        rnetwork::packet::StartGamePacket packet;
        clientChannel->tcpSend(packet);
    }, 4);
    ioService.registerTask(task);
    ioService.registerTask(task2);
    ioService.registerTask(task3);

    ioService.run();
    std::cout << "No task remaining" << std::endl;
    rnetwork::clean();
    return 0;
}
