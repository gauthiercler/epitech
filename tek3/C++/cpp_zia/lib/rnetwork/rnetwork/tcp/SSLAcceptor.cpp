#include <rnetwork/exceptions/AcceptError.hpp>
#include <rnetwork/exceptions/InvalidSocket.hpp>
#include "SSLAcceptor.hpp"
#include "SSLClient.hpp"

rnetwork::tcp::SSLAcceptor::SSLAcceptor(rnetwork::async::IOService &ioService, const rnetwork::Endpoint &endpoint, const std::string &cert, const std::string &key, unsigned int queueSize) :
    Acceptor(ioService, endpoint, queueSize),
    _cert(cert),
    _key(key)
{
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    _sslctx = SSL_CTX_new( SSLv23_server_method());
    if (!_sslctx)
        throw rnetwork::exceptions::InvalidSocket("Unable to load ssl context");
    SSL_CTX_set_ecdh_auto(_sslctx, 1);
    if (SSL_CTX_use_certificate_file(_sslctx, cert.c_str() , SSL_FILETYPE_PEM) <= 0)
        throw rnetwork::exceptions::InvalidSocket("Unable to load certificate");
    if (SSL_CTX_use_PrivateKey_file(_sslctx, key.c_str(), SSL_FILETYPE_PEM) <= 0)
        throw rnetwork::exceptions::InvalidSocket("Unable to load key");
}

std::shared_ptr<rnetwork::IClient> rnetwork::tcp::SSLAcceptor::accept(bool &status) const {
    SOCKET sock;
    SOCKADDR_IN remote = {0};
    int remoteSize = sizeof(remote);
    SSL *sslSocket;

    sock = ::accept(_socket, reinterpret_cast<SOCKADDR *>(&remote), reinterpret_cast<socklen_t *>(&remoteSize));
    if(sock == INVALID_SOCKET)
        throw rnetwork::exceptions::AcceptError("Unable to accept new client.");
    sslSocket = SSL_new(_sslctx);
    SSL_set_fd(sslSocket, sock);
    if (SSL_accept(sslSocket) <= 0) {
        SSL_free(sslSocket);
        close(sock);
        throw rnetwork::exceptions::AcceptError("Unable to accept ssl client");
    }
    status = true;
    return std::make_shared<rnetwork::tcp::SSLClient>(_ioService, sock, sslSocket, &remote);
}

rnetwork::tcp::SSLAcceptor::~SSLAcceptor() {
    SSL_CTX_free(_sslctx);
    EVP_cleanup();
}
