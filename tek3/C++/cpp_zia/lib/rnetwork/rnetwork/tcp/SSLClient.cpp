#include "SSLClient.hpp"

rnetwork::tcp::SSLClient::~SSLClient() {
    SSL_free(_ssl);
}

rnetwork::tcp::SSLClient::SSLClient(rnetwork::async::IOService &ioService, SOCKET socket, SSL *ssl, SOCKADDR_IN *remote) :
    Client(ioService, socket, remote),
    _ssl(ssl)
{}

std::shared_ptr<rnetwork::packet::PacketBase> rnetwork::tcp::SSLClient::receive(bool &status) {
    unsigned char buff[MAX_TCP_SIZE];
    uint16_t packetSize;

    packetSize = static_cast<uint16_t>(SSL_read(_ssl, reinterpret_cast<char *>(buff), MAX_TCP_SIZE));
    status = packetSize > 0;
    return std::make_shared<rnetwork::packet::PacketBase>(buff, packetSize);
}

bool
rnetwork::tcp::SSLClient::send(const rnetwork::packet::IPacket &packet) const {
    return ::SSL_write(_ssl, reinterpret_cast<const char *>(packet.raw()), packet.size()) > 0;
}

rnetwork::tcp::SSLClient::SSLClient(rnetwork::async::IOService &ioService)
    : Client(ioService) {
}

rnetwork::tcp::SSLClient::SSLClient(rnetwork::async::IOService &ioService,
                                    const rnetwork::Endpoint &endpoint)
    : Client(ioService, endpoint) {
}
