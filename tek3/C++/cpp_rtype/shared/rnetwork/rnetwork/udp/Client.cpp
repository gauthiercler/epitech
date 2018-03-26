#include <iostream>
#include "rnetwork/udp/Client.hpp"
#include "rnetwork/exceptions/InvalidSocket.hpp"
#include "rnetwork/exceptions/BadHostname.hpp"
#include "rnetwork/exceptions/IOError.hpp"
#include "rnetwork/tasks/SendTask.hpp"
#include "rnetwork/tasks/ReceiveTask.hpp"

rnetwork::udp::Client::Client(const rnetwork::Endpoint &endpoint, rnetwork::async::IOService &ioService) :
        _ioService(ioService),
        _socket(::socket(AF_INET, SOCK_DGRAM, 0)),
        _endpoint(endpoint)
{
    if (_socket == INVALID_SOCKET)
        throw rnetwork::exceptions::InvalidSocket("Unable to create udp client socket");
    _link(endpoint);
}

rnetwork::udp::Client::Client(const SOCKADDR_IN *endpoint, rnetwork::async::IOService &ioService) :
        _ioService(ioService),
        _socket(::socket(AF_INET, SOCK_DGRAM, 0)),
        _remote(*endpoint),
        _endpoint(inet_ntoa(_remote.sin_addr), _remote.sin_port)
{
    if (_socket == INVALID_SOCKET)
        throw rnetwork::exceptions::InvalidSocket("Unable to create udp client socket");
}

rnetwork::udp::Client::Client(const rnetwork::udp::Client &client) :
        _ioService(client._ioService),
        _socket(::socket(AF_INET, SOCK_DGRAM, 0)),
        _remote(client._remote),
        _endpoint(client._endpoint)
{
    if (_socket == INVALID_SOCKET)
        throw rnetwork::exceptions::InvalidSocket("Unable to create udp client socket");
}

rnetwork::udp::Client::~Client() {
    closesocket(_socket);
}

rnetwork::udp::Client &rnetwork::udp::Client::operator=(const rnetwork::udp::Client &client) {
    if (this != &client)
        _remote = client._remote;
    return *this;
}

void rnetwork::udp::Client::_link(const rnetwork::Endpoint &endpoint) {
    struct hostent *hostinfo = nullptr;

    hostinfo = gethostbyname(endpoint.host().c_str());
    if (hostinfo == nullptr)
        throw rnetwork::exceptions::BadHostname(endpoint.host());
    this->_remote.sin_addr = *(IN_ADDR *)hostinfo->h_addr;
    this->_remote.sin_port = htons(endpoint.port());
    this->_remote.sin_family = AF_INET;
}

bool rnetwork::udp::Client::send(rnetwork::packet::IPacket const& packet) const {
    ssize_t status = sendto(this->_socket, reinterpret_cast<const char *>(packet.raw()), packet.size(), 0, reinterpret_cast<const SOCKADDR *>(&this->_remote), sizeof(this->_remote));
    return status >= 0;
}

std::shared_ptr<rnetwork::packet::PacketBase> rnetwork::udp::Client::receive(bool &status) {
    ssize_t size;
    unsigned char buff[MAX_UDP_SIZE];
    unsigned int remoteSize = sizeof(_remote);
    SOCKADDR_IN remote = _remote;

    size = recvfrom(this->_socket, reinterpret_cast<char *>(buff), MAX_UDP_SIZE, 0,
                    reinterpret_cast<SOCKADDR *>(&remote), reinterpret_cast<socklen_t *>(&remoteSize));
    status = size > 0;
    return std::make_shared<rnetwork::packet::PacketBase>(buff, (size >= 0) ? size : 0, &this->_remote);
}

std::shared_ptr<rnetwork::packet::PacketBase> rnetwork::udp::Client::receive() {
    bool status;
    return receive(status);
}

SOCKET rnetwork::udp::Client::socket() const {
    return _socket;
}

void rnetwork::udp::Client::async_send(rnetwork::packet::IPacket const& packet, const std::function<void(bool)> &callback) {
    auto packetPtr = packet.snapshot();
    auto task = std::make_shared<rnetwork::tasks::SendTask>(shared_from_this(), packetPtr, callback);
    _ioService.registerTask(task);
}

void rnetwork::udp::Client::async_receive(const std::function<void(rnetwork::packet::PacketBase&, bool status)> &callback) {
    auto task = std::make_shared<rnetwork::tasks::ReceiveTask>(shared_from_this(), callback);
    _ioService.registerTask(task);
}

const rnetwork::Endpoint &rnetwork::udp::Client::getEndpoint() const {
    return _endpoint;
}
