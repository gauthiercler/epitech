#ifndef CPP_ZIA_SSLACCEPTOR_HPP
#define CPP_ZIA_SSLACCEPTOR_HPP

#include <openssl/ssl.h>
#include "Acceptor.hpp"

namespace rnetwork
{
  namespace tcp
  {
    class SSLAcceptor : public Acceptor {
    private:
        SSL_CTX *_sslctx;
        std::string _cert;
        std::string _key;

    public:
        SSLAcceptor(rnetwork::async::IOService &ioService, const rnetwork::Endpoint &endpoint, const std::string &cert, const std::string &key, unsigned int queueSize = 10);
        SSLAcceptor(const Acceptor &) = delete;
        virtual ~SSLAcceptor();

        std::shared_ptr<rnetwork::IClient> accept(bool &status) const override;

        SSLAcceptor &operator=(const SSLAcceptor &) = delete;

    };
  }
}

#endif //CPP_ZIA_SSLACCEPTOR_HPP
