#include <rnetwork/exceptions/BadHostname.hpp>
#include <rnetwork/exceptions/ConnectionError.hpp>
#include <rnetwork/tasks/SendTask.hpp>
#include <rnetwork/tasks/ReceiveTask.hpp>
#include <iostream>
#include "rnetwork/exceptions/InvalidSocket.hpp"
#include "Client.hpp"

#ifdef WIN32
#	define MSG_NOSIGNAL 0
#endif

rnetwork::tcp::Client::Client(rnetwork::async::IOService &ioService) :
        _ioService(ioService),
        _endpoint("0.0.0.0", 0),
        _socket(::socket(AF_INET, SOCK_STREAM, 0))
{
    if(_socket == INVALID_SOCKET)
        throw rnetwork::exceptions::InvalidSocket("Unable to create socket");
}

rnetwork::tcp::Client::Client(rnetwork::async::IOService &ioService, SOCKET socket, SOCKADDR_IN *remote) :
        _ioService(ioService),
        _endpoint(getRemoteHost(remote), getRemotePort(remote)),
        _socket(std::move(socket))
{
    if(_socket == INVALID_SOCKET)
        throw rnetwork::exceptions::InvalidSocket("Invalid socket given to new instance of tcp client.");
}

rnetwork::tcp::Client::Client(rnetwork::async::IOService &ioService, const rnetwork::Endpoint &endpoint) :
        Client(ioService)
{
    bool status = connect(endpoint);
    if (!status)
        throw rnetwork::exceptions::ConnectionError("Unable to connect to " + endpoint);
}

rnetwork::tcp::Client::~Client() {
    closesocket(_socket);
}

SOCKET rnetwork::tcp::Client::socket() const {
    return _socket;
}

bool rnetwork::tcp::Client::connect(const rnetwork::Endpoint &endpoint) {
    struct hostent *hostinfo = nullptr;
    SOCKADDR_IN sin = {0};

    hostinfo = gethostbyname(endpoint.host().c_str());
    if (hostinfo == nullptr)
        throw rnetwork::exceptions::BadHostname(endpoint.host());
    sin.sin_addr = *reinterpret_cast<IN_ADDR *>(hostinfo->h_addr);
    sin.sin_port = htons(endpoint.port());
    sin.sin_family = AF_INET;
    return ::connect(_socket, reinterpret_cast<SOCKADDR *>(&sin), sizeof(SOCKADDR)) != SOCKET_ERROR;
}

bool rnetwork::tcp::Client::send(packet::IPacket const& packet) const {
    return ::send(_socket, reinterpret_cast<const char *>(packet.raw()), packet.size(), MSG_NOSIGNAL) > 0;
}

std::shared_ptr<rnetwork::packet::PacketBase> rnetwork::tcp::Client::receive(bool &status) {
  unsigned char buff[MAX_TCP_SIZE];
  uint16_t packetSize;

  packetSize = static_cast<uint16_t>(::recv(_socket, reinterpret_cast<char *>(buff), MAX_TCP_SIZE, 0));
  status = packetSize > 0;
  return std::make_shared<rnetwork::packet::PacketBase>(buff, packetSize);
  /*
   * No need to use binnary header so have a simple implementation
   *
  ssize_t sizeHeader;
  ssize_t size = 0;

  sizeHeader = ::recv(_socket, reinterpret_cast<char *>(buff), HEADER_SIZE, 0);
  packetSize = ntohs(*reinterpret_cast<uint16_t *>(buff));
  if (sizeHeader > 0 && packetSize > 0)
      size = ::recv(_socket, reinterpret_cast<char *>(&buff[HEADER_SIZE]), packetSize, 0);
  status = sizeHeader > 0 || size > 0;
  return std::make_shared<rnetwork::packet::PacketBase>(buff, (sizeHeader + size > 0) ? sizeHeader + size : 0);*/
}

std::shared_ptr<rnetwork::packet::PacketBase> rnetwork::tcp::Client::receive() {
    bool status;
    return receive(status);
}

void rnetwork::tcp::Client::async_send(
	packet::IPacket const& packet,
	const std::function<void(bool)>& callback) {
    auto packetPtr = packet.snapshot();
    auto task = std::make_shared<rnetwork::tasks::SendTask>(shared_from_this(), packetPtr, callback);
    _ioService.registerTask(task);
}

void
rnetwork::tcp::Client::async_receive(const std::function<void(rnetwork::packet::PacketBase &, bool status)> &callback) {
    auto task = std::make_shared<rnetwork::tasks::ReceiveTask>(shared_from_this(), callback);
    _ioService.registerTask(task);
}

std::string rnetwork::tcp::Client::getRemoteHost(SOCKADDR_IN *remote) const {
    return inet_ntoa(remote->sin_addr);
}

uint16_t rnetwork::tcp::Client::getRemotePort(SOCKADDR_IN *remote) const {
    return remote->sin_port;
}

const rnetwork::Endpoint &rnetwork::tcp::Client::getEndpoint() const {
    return _endpoint;
}