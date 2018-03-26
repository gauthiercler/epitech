#ifndef CPP_ZIA_SSLCLIENT_HPP
#define CPP_ZIA_SSLCLIENT_HPP

#include <openssl/ssl.h>
#include "Client.hpp"
#include <rnetwork/packet/PacketBase.hpp>

namespace rnetwork {
  namespace tcp {
    class SSLClient : public Client {
    private:
        SSL *_ssl;
    public:
        explicit SSLClient(rnetwork::async::IOService &ioService);
        SSLClient(rnetwork::async::IOService &ioService, SOCKET socket, SSL *ssl, SOCKADDR_IN *remote);
        explicit SSLClient(rnetwork::async::IOService &ioService, const rnetwork::Endpoint &endpoint);
        SSLClient(const Client &client) = delete;
        ~SSLClient() override;

        bool send(packet::IPacket const& packet) const override;
        std::shared_ptr<rnetwork::packet::PacketBase> receive(bool &status) override;

        SSLClient &operator=(const SSLClient &) = delete;
    };
  }
}


#endif //CPP_ZIA_SSLCLIENT_HPP
