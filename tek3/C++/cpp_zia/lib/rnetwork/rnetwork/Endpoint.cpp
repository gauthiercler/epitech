#include "Endpoint.hpp"

rnetwork::Endpoint::Endpoint(const std::string &host, uint16_t port) :
        _host(host),
        _port(port) {}

const std::string &rnetwork::Endpoint::host() const {
    return _host;
}

const uint16_t rnetwork::Endpoint::port() const {
    return _port;
}

rnetwork::Endpoint::Endpoint(const SOCKADDR_IN *addr) :
        _host(inet_ntoa(addr->sin_addr)),
        _port(addr->sin_port)
{}

bool rnetwork::Endpoint::operator==(const rnetwork::Endpoint &endpoint) const {
    return _host == endpoint._host && _port == endpoint._port;
}

std::string operator+(const std::string &str, const rnetwork::Endpoint &endpoint)
{
    return str + endpoint.host() + ":" + std::to_string(endpoint.port());
}

std::ostream &operator<<(std::ostream &os, const rnetwork::Endpoint &endpoint)
{
    os << endpoint.host() << std::string(":") << std::to_string(endpoint.port());
    return os;
}