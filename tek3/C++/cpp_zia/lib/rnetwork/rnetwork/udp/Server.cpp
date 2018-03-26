#include "rnetwork/exceptions/BadHostname.hpp"
#include "rnetwork/tasks/ReceiveTask.hpp"
#include "rnetwork/exceptions/InvalidSocket.hpp"
#include "rnetwork/exceptions/BadBind.hpp"
#include "Server.hpp"

rnetwork::udp::Server::Server(rnetwork::async::IOService &ioService) :
        _ioService(ioService),
        _socket(::socket(AF_INET, SOCK_DGRAM, 0))
{
    if (_socket == INVALID_SOCKET)
        throw rnetwork::exceptions::InvalidSocket("Unable to create server's socket");
}

rnetwork::udp::Server::Server(rnetwork::async::IOService &ioService, const rnetwork::Endpoint &endpoint) :
        Server(ioService)
{
    if (!bind(endpoint))
        throw rnetwork::exceptions::BadBind("Unable to bind host " + endpoint);
}

rnetwork::udp::Server::~Server() {
    closesocket(_socket);
}

bool rnetwork::udp::Server::bind(const rnetwork::Endpoint &endpoint) {
    SOCKADDR_IN sockaddr_in = {0};
    struct hostent *hostinfo = nullptr;
    char reuse = 1;

    setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int));
    hostinfo = gethostbyname(endpoint.host().c_str());
    if (hostinfo == nullptr)
        throw rnetwork::exceptions::BadHostname(endpoint.host());
    sockaddr_in.sin_addr = *reinterpret_cast<IN_ADDR *>(hostinfo->h_addr);
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_port = htons(endpoint.port());
    return ::bind(this->_socket, reinterpret_cast<SOCKADDR *>(&sockaddr_in), sizeof(sockaddr_in)) != SOCKET_ERROR;
}

std::shared_ptr<rnetwork::packet::PacketBase> rnetwork::udp::Server::receive(bool &status) {
    ssize_t size;
    unsigned char buff[MAX_UDP_SIZE];
    SOCKADDR_IN from = { 0 };
    unsigned int fromSize = sizeof(from);

    size = recvfrom(this->_socket, reinterpret_cast<char *>(buff), MAX_UDP_SIZE, 0,
                    reinterpret_cast<SOCKADDR *>(&from), reinterpret_cast<socklen_t *>(&fromSize));
    status = size > 0;
    return std::make_shared<rnetwork::packet::PacketBase>(buff, (size >= 0) ? size : 0, &from);
}

std::shared_ptr<rnetwork::packet::PacketBase> rnetwork::udp::Server::receive() {
    bool status;
    return receive(status);
}

SOCKET rnetwork::udp::Server::socket() const {
    return _socket;
}

void rnetwork::udp::Server::async_receive(const std::function<void(rnetwork::packet::PacketBase &, bool status)> &callback) {
    auto task = std::make_shared<rnetwork::tasks::ReceiveTask>(shared_from_this(), callback);
    _ioService.registerTask(task);
}

rnetwork::async::IOService &rnetwork::udp::Server::ioService() {
    return _ioService;
}
