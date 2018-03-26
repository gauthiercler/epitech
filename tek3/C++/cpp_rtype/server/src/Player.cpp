//
// Created by ventinc on 1/19/18.
//

#include <ClientChannel.hpp>
#include <server/include/Player.hpp>
#include <packet/LobbyEntryPacket.hpp>
#include <iostream>
#include <packet/LobbyJoinPacket.hpp>
#include <packet/StartGamePacket.hpp>
#include <packet/Opcodes.hpp>
#include <packet/LobbyLeavePacket.hpp>

rtypeserver::Player::Player(const std::shared_ptr <rnetwork::ClientChannel>& channel, uint16_t id) :
        _channel(channel),
        _id(id)
{
    initRouter();
}

bool
rtypeserver::Player::haveChannel(const std::shared_ptr<rnetwork::ClientChannel>& channel) const
{
    return _channel == channel;
}

void rtypeserver::Player::initRouter() {
	using Packet = rnetwork::packet::PacketBase;

    _router.registerRoute(rnetwork::packet::op::LobbyEntryPacket, std::bind(&rtypeserver::Player::sendTCP, this, std::placeholders::_1));
    _router.registerRoute(rnetwork::packet::op::LobbyJoinPacket, std::bind(&rtypeserver::Player::sendTCP, this, std::placeholders::_1));
    _router.registerRoute(rnetwork::packet::op::StartGamePacket, [&](Packet const& packet) { _channel->tcpSend(packet); });
	_router.registerRoute(rnetwork::packet::op::EntitySpawn, [&](Packet const& packet) { _channel->tcpSend(packet); });
    _router.registerRoute(rnetwork::packet::op::MovePacket, [&](Packet const& packet) { _channel->udpSend(packet); });
    _router.registerRoute(rnetwork::packet::op::PlayerJoinedPacket, [&](Packet const& packet) { _channel->tcpSend(packet); });
    _router.registerRoute(rnetwork::packet::op::PlayerLeavedPacket, [&](Packet const& packet) { _channel->tcpSend(packet); });
    _router.registerRoute(rnetwork::packet::op::LobbyLeavePacket, [&](Packet const& packet) { _channel->tcpSend(packet); });
}

void rtypeserver::Player::send(rnetwork::packet::PacketBase const& packet) {
    if (_router.isRegistered(packet.getOp()))
        _router(packet);
    else
        std::clog << "[INFO] Dropped unknown output packet (op: " << packet.getOp() << ")" << std::endl;
}

void rtypeserver::Player::sendTCP(rnetwork::packet::PacketBase const& packet) {
    _channel->tcpSend(packet);
}

void rtypeserver::Player::joinGame(std::shared_ptr<rtypeserver::Game> game) {
    rnetwork::packet::LobbyJoinPacket packet(game->getId());

    if (_game)
        _game->unregisterPlayer(shared_from_this());
    _game = game;
    send(packet);
}

std::shared_ptr<rtypeserver::Game> rtypeserver::Player::getGame() const {
    return _game;
}

rtypeserver::Player::RouterReceiver& rtypeserver::Player::routerReceiver()
{
    return _receiver;
}

rtypeserver::Player::RouterSender& rtypeserver::Player::routerSender()
{
    return _router;
}

void rtypeserver::Player::leaveGame() {
    rnetwork::packet::LobbyLeavePacket packet;
    _game = nullptr;
    send(packet);
}

uint16_t rtypeserver::Player::getId() const {
    return _id;
}
