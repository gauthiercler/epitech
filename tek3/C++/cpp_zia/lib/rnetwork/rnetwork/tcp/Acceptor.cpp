#include "Acceptor.hpp"
#include "rnetwork/tasks/AcceptTask.hpp"
#include "rnetwork/exceptions/BadHostname.hpp"
#include "rnetwork/exceptions/AcceptError.hpp"
#include "rnetwork/exceptions/InvalidSocket.hpp"
#include "rnetwork/exceptions/BadBind.hpp"
#include "rnetwork/exceptions/BadListen.hpp"

rnetwork::tcp::Acceptor::Acceptor(rnetwork::async::IOService &ioService, const rnetwork::Endpoint &endpoint, unsigned int queueSize) :
        _ioService(ioService),
        _socket(::socket(AF_INET, SOCK_STREAM, 0))
{
    if (_socket == INVALID_SOCKET)
        throw rnetwork::exceptions::InvalidSocket("Unable to create socket");
    if (!bind(endpoint))
        throw rnetwork::exceptions::BadBind("Unable to bind " + endpoint);
    if (!listen(queueSize))
        throw rnetwork::exceptions::BadListen("Unable to listen for " + std::to_string(queueSize) + " clients");
}

rnetwork::tcp::Acceptor::~Acceptor() {
    closesocket(_socket);
}

bool rnetwork::tcp::Acceptor::bind(const rnetwork::Endpoint &endpoint) const {
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

bool rnetwork::tcp::Acceptor::listen(unsigned int queueSize) const {
    return ::listen(_socket, queueSize) != SOCKET_ERROR;
}

std::shared_ptr<rnetwork::IClient> rnetwork::tcp::Acceptor::accept() const
{
    bool status;
    return accept(status);
}

std::shared_ptr<rnetwork::IClient> rnetwork::tcp::Acceptor::accept(bool &status) const {
    SOCKET sock;
    SOCKADDR_IN remote = {0};
    int remoteSize = sizeof(remote);

    sock = ::accept(_socket, reinterpret_cast<SOCKADDR *>(&remote), reinterpret_cast<socklen_t *>(&remoteSize));
    if(sock == INVALID_SOCKET)
        throw rnetwork::exceptions::AcceptError("Unable to accept new client.");
    status = true;
    return std::make_shared<rnetwork::tcp::Client>(_ioService, std::move(sock), &remote);
}

void rnetwork::tcp::Acceptor::async_accept(const std::function<void(std::shared_ptr<rnetwork::IClient> client, bool status)> &callback) {
    auto task = std::make_shared<rnetwork::tasks::AcceptTask>(shared_from_this(), callback);
    _ioService.registerTask(task);
}

SOCKET rnetwork::tcp::Acceptor::socket() const {
    return _socket;
}

rnetwork::async::IOService &rnetwork::tcp::Acceptor::ioService() {
    return _ioService;
}
