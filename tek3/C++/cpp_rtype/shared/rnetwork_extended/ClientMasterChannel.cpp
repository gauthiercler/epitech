#include <iostream>
#include <packet/UDPTokenPacket.hpp>
#include <algorithm>
#include <packet/Opcodes.hpp>
#include "ClientMasterChannel.hpp"

rnetwork::ClientMasterChannel::ClientMasterChannel(rnetwork::async::IOService &ioService,
                                                   const rnetwork::Endpoint &tpcEndpoint,
                                                   const rnetwork::Endpoint &udpEndpoint) :
        _ioService(ioService),
        _tcpAcceptor(std::make_shared<rnetwork::tcp::Acceptor>(ioService, tpcEndpoint)),
        _udpServer(std::make_shared<rnetwork::udp::Server>(ioService, udpEndpoint)),
        _udpEndpoint(udpEndpoint)
{}

void rnetwork::ClientMasterChannel::start() {
    std::clog << "[INFO] Start Client master channel" << std::endl;
    initRouter();
    _tcpAcceptor->async_accept(std::bind(&rnetwork::ClientMasterChannel::handleConnection, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    _udpServer->async_receive(std::bind(&rnetwork::ClientMasterChannel::handlePacket, shared_from_this(), _udpServer, std::placeholders::_1, std::placeholders::_2));
}

void rnetwork::ClientMasterChannel::handleConnection(std::shared_ptr<rnetwork::IClient> client, bool status) {
    if (status) {
        auto clientChannel = std::make_shared<rnetwork::ClientChannel>(_ioService);
        clientChannel->setGateway(_gateway);
        clientChannel->setDisconnectCallback(std::bind(&rnetwork::ClientMasterChannel::handleDisconnection, shared_from_this(), std::placeholders::_1));
        clientChannel->generateIdentifier();
        clientChannel->handleHandshake(std::move(client), _udpEndpoint);
        std::clog << "[INFO] Start handshake for " << clientChannel->getIdentitfier() << std::endl;
        _clients.emplace(clientChannel->getIdentitfier(), clientChannel);
        _tcpAcceptor->async_accept(std::bind(&rnetwork::ClientMasterChannel::handleConnection, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    } else
        std::clog << "[WARNING] An error occurring accepting new client. Stop listening for new clients." << std::endl;
}

void rnetwork::ClientMasterChannel::handlePacket(std::shared_ptr<rnetwork::IReceiver> receiver, rnetwork::packet::PacketBase &packet, bool status) {
    if (status) {
        if (_router.isRegistered(packet.getOp())) {
            _router(packet, getClient(packet.getRemote()));
        } else if (_gateway)
            _gateway(getChannel(packet.getRemote()), packet);
        else
            std::clog << "[INFO] Packet drop due of lack of gateway" << std::endl;
        receiver->async_receive(std::bind(&rnetwork::ClientMasterChannel::handlePacket, shared_from_this(), receiver, std::placeholders::_1, std::placeholders::_2));
    } else
        std::clog << "[WARNING] An error occurred while recieving packet. Stop listening for new packets" << std::endl;
}

void rnetwork::ClientMasterChannel::initRouter() {
    _router.registerRoute(packet::op::UdpTokenPacket, std::bind(&rnetwork::ClientMasterChannel::handleTokenId, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void rnetwork::ClientMasterChannel::handleTokenId(rnetwork::packet::PacketBase &packet, std::shared_ptr<rnetwork::IClient> client) {
    rnetwork::packet::UDPTokenPacket tokenPacket(packet);

    auto chanel = getChannel(tokenPacket.getToken());
    if (chanel) {
        chanel->finalizeHandshake(packet.generateClient<rnetwork::udp::Client>(_ioService));
        std::clog << "[INFO] Successful handshake with " << chanel->getIdentitfier() << std::endl;
        if (_connection)
            _connection(chanel);
    }
}

std::shared_ptr<rnetwork::IClient> rnetwork::ClientMasterChannel::getClient(const rnetwork::Endpoint &endpoint) const {
    auto channel = getChannel(endpoint);
    if (channel)
        return channel->getClient(endpoint);
    else
        return nullptr;
}

std::shared_ptr<rnetwork::ClientChannel> rnetwork::ClientMasterChannel::getChannel(const rnetwork::Endpoint &endpoint) const {
    auto channel = std::find_if(_clients.begin(), _clients.end(), [&](const std::pair<std::string, std::shared_ptr<ClientChannel>> &channel) {
        return channel.second->is(endpoint);
    });
    if (channel == _clients.end())
        return nullptr;
    else
        return channel->second;
}

std::shared_ptr<rnetwork::ClientChannel> rnetwork::ClientMasterChannel::getChannel(const std::string &identifier) const {
    auto channel = std::find_if(_clients.begin(), _clients.end(), [&](const std::pair<std::string, std::shared_ptr<ClientChannel>> &channel) {
        return channel.second->getIdentitfier() == identifier;
    });
    if (channel == _clients.end())
        return nullptr;
    else
        return channel->second;}

void rnetwork::ClientMasterChannel::setGateway(const std::function<void(std::shared_ptr<rnetwork::ClientChannel>, rnetwork::packet::PacketBase &)> &gateway) {
    _gateway = gateway;
}

void rnetwork::ClientMasterChannel::setConnectionCallback(const std::function<void(std::shared_ptr<rnetwork::ClientChannel>)> &connectionCallback) {
    _connection = connectionCallback;
}

void rnetwork::ClientMasterChannel::setDisconnectionCallback(const std::function<void(std::shared_ptr<rnetwork::ClientChannel>)> &disconnectionCallback) {
    _disconnection = disconnectionCallback;
}

void rnetwork::ClientMasterChannel::handleDisconnection(std::shared_ptr<rnetwork::ClientChannel> client) {
    _clients.erase(client->getIdentitfier());
    _disconnection(client);
}
