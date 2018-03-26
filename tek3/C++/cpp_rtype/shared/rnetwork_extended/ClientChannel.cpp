#include <iostream>
#include <algorithm>
#include <functional>
#include <packet/UDPTokenPacket.hpp>
#include <packet/UDPHostPacket.hpp>
#include <rnetwork/tasks/DelayedTask.hpp>
#include <packet/AssociationPacket.hpp>
#include <rnetwork/tasks/ExecTask.hpp>
#include <packet/Opcodes.hpp>
#include "ClientChannel.hpp"

rnetwork::ClientChannel::ClientChannel(rnetwork::async::IOService &ioService) :
        _ioService(ioService),
        _tcpEndpoint("0.0.0.0", 0),
        _udpEndpoint("0.0.0.0", 0) {}

void rnetwork::ClientChannel::handshake(const rnetwork::Endpoint &tcpEndpoint) {
    initRouter();
    _tcpEndpoint = tcpEndpoint;
    _tcpClient = std::make_shared<rnetwork::tcp::Client>(_ioService, tcpEndpoint);
    _tcpClient->async_receive(std::bind(&rnetwork::ClientChannel::handlePacket, shared_from_this(), _tcpClient, std::placeholders::_1, std::placeholders::_2));
}

void rnetwork::ClientChannel::handlePacket(std::shared_ptr<rnetwork::IClient> client, rnetwork::packet::PacketBase &packet, bool status) {
    if (status) {
        if (_router.isRegistered(packet.getOp())) {
            _router(packet, client);
        } else if (isAssociated() && _gateway)
            _gateway(shared_from_this(), packet);
        else
            std::clog << "[INFO] Packet dropped (OP: " << packet.getOp() << ")" << std::endl;
        client->async_receive(std::bind(&rnetwork::ClientChannel::handlePacket, shared_from_this(), client, std::placeholders::_1, std::placeholders::_2));
    } else if (_disconnectCallback)
        _disconnectCallback(shared_from_this());
}

void rnetwork::ClientChannel::initRouter() {
    _router.registerRoute(packet::op::UdpTokenPacket, std::bind(&rnetwork::ClientChannel::handleTokenPacket, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    _router.registerRoute(packet::op::UdpHostPacket, std::bind(&rnetwork::ClientChannel::handleHostPacket, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    _router.registerRoute(packet::op::AssociationPacket, std::bind(&rnetwork::ClientChannel::handleAssociationPacket, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void rnetwork::ClientChannel::handleHandshake(std::shared_ptr<rnetwork::IClient> client, const rnetwork::Endpoint &udpEndpoint) {
    rnetwork::packet::UDPTokenPacket tokenPacket(_identifier);
    rnetwork::packet::UDPHostPacket hostPacket(udpEndpoint);

    initRouter();
    _tcpClient = std::move(client);
    _tcpEndpoint = _tcpClient->getEndpoint();
    _udpEndpoint = _udpEndpoint;
    _tcpClient->async_send(tokenPacket, [&](bool) {});
    _tcpClient->async_send(hostPacket, [&](bool) {});
    _tcpClient->async_receive(std::bind(&rnetwork::ClientChannel::handlePacket, shared_from_this(), _tcpClient, std::placeholders::_1, std::placeholders::_2));
}

void rnetwork::ClientChannel::handleTokenPacket(rnetwork::packet::PacketBase &packet, std::shared_ptr<rnetwork::IClient> client) {
    rnetwork::packet::UDPTokenPacket tokenPacket(packet);

    std::clog << "[Handshake] Received token" << std::endl;
    _identifier = tokenPacket.getToken();
}

void rnetwork::ClientChannel::handleHostPacket(rnetwork::packet::PacketBase &packet, std::shared_ptr<rnetwork::IClient> client) {
    std::clog << "[Handshake] Received host" << std::endl;
    if (!_identifier.empty()) {
        rnetwork::packet::UDPHostPacket hostPacket(packet);
        _udpEndpoint = rnetwork::Endpoint(_tcpEndpoint.host(), hostPacket.getEndpoint().port()); // Packet host might be inconsistent
        sendUDPToken(_udpEndpoint);
    } else {
        std::clog << "[Handshake] Delay packet management" << std::endl;
        auto packetPtr = std::make_shared<rnetwork::packet::PacketBase>(packet);
        auto task = std::make_shared<rnetwork::tasks::DelayedTask>([that = shared_from_this(), client, packetPtr]() {
            that->handleHostPacket(*packetPtr, client);
        }, 1);
        _ioService.registerTask(task);
    }
}

void rnetwork::ClientChannel::setIdentifier(const std::string &identifier) {
    _identifier = identifier;
}

const std::string &rnetwork::ClientChannel::getIdentitfier() const {
    return _identifier;
}

void rnetwork::ClientChannel::sendUDPToken(const rnetwork::Endpoint &endpoint) {
    rnetwork::packet::UDPTokenPacket tokenPacket(_identifier);

    _udpClient = std::make_shared<rnetwork::udp::Client>(endpoint, _ioService);
    _udpClient->async_send(tokenPacket, [&](bool status) {
        if (!status)
            std::clog << "[Handshake] UDP registration failed" << std::endl;
    });
}

void rnetwork::ClientChannel::generateIdentifier() {
    constexpr const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    constexpr const size_t maxIndex = (sizeof(charset) - 1);

    _identifier.resize(4, 0);
    for (auto &c : _identifier) {

		/// TODO: Better rand algotithm.
        c = charset[std::rand() % maxIndex];
    }
}

bool rnetwork::ClientChannel::is(const rnetwork::Endpoint &endpoint) {
    return (_tcpClient && _tcpClient->getEndpoint() == endpoint) ||
           (_udpClient && _udpClient->getEndpoint() == endpoint);
}

std::shared_ptr<rnetwork::IClient> rnetwork::ClientChannel::getClient(const rnetwork::Endpoint &endpoint) {
    if (_tcpClient && _tcpClient->getEndpoint() == endpoint)
        return _tcpClient;
    else if (_udpClient && _udpClient->getEndpoint() == endpoint)
        return _udpClient;
    else
        return nullptr;
}

void rnetwork::ClientChannel::finalizeHandshake(std::shared_ptr<rnetwork::IClient> client) {
    rnetwork::packet::AssociationPacket associationPacket;

    _udpClient = std::move(client);
    _associated = true;
    _tcpClient->async_send(associationPacket, [&](bool status) {});
    _router.clear();
}

void rnetwork::ClientChannel::handleAssociationPacket(rnetwork::packet::PacketBase &, std::shared_ptr<rnetwork::IClient>) {
    std::clog << "[INFO] Handshake successful" << std::endl;
    _udpClient->async_receive(std::bind(&rnetwork::ClientChannel::handlePacket, shared_from_this(), _udpClient, std::placeholders::_1, std::placeholders::_2));
    _associated = true;
    _router.clear();
}

bool rnetwork::ClientChannel::isAssociated() const {
    return _associated;
}

void rnetwork::ClientChannel::tcpSend(rnetwork::packet::IPacket const& packet) const {
    _tcpClient->async_send(packet, [&](bool status) {
        if (!status)
            std::clog << "[WARNING][TCP] Failed to send packet." << std::endl;
    });
}

bool rnetwork::ClientChannel::udpSend(rnetwork::packet::IPacket const& packet) {
    if (!isAssociated()) {
        if (_udpEndpoint.host() != "0.0.0.0" && _udpEndpoint.port() != 0 && _identifier.empty())
            sendUDPToken(_udpEndpoint);
        return false;
    }
    _udpClient->async_send(packet, {[&](bool status) {
        if (!status)
            std::clog << "[WARNING][UDP] Failed to send packet." << std::endl;
    }});
	return (true);
}

void rnetwork::ClientChannel::setGateway(const std::function<void(std::shared_ptr<rnetwork::ClientChannel>, rnetwork::packet::PacketBase &)> &gateway) {
    _gateway = gateway;
}

void rnetwork::ClientChannel::setDisconnectCallback(const std::function<void(std::shared_ptr<rnetwork::ClientChannel>)> &callback) {
    _disconnectCallback = callback;
}
