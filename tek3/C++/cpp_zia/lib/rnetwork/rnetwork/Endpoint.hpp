#ifndef CPP_RTYPE_ENDPOINT_HPP
#define CPP_RTYPE_ENDPOINT_HPP

#include <string>
#include "config/Export.hpp"
#include "rnetwork/rnetwork.hpp"

namespace rnetwork
{
    class RNETWORK_API Endpoint
    {
    private:
        std::string _host;
        uint16_t _port;

    public:
        Endpoint(const std::string &host, uint16_t port);
        explicit Endpoint(const SOCKADDR_IN *addr);
        Endpoint(const Endpoint &endpoint) = default;
        virtual ~Endpoint() = default;

        const std::string &host() const;
        const uint16_t port() const;

        Endpoint &operator=(const Endpoint &endpoint) = default;
        bool operator==(const Endpoint &endpoint) const;
    };
}

std::string operator+(const std::string &str, const rnetwork::Endpoint &endpoint);
std::ostream &operator<<(std::ostream &os, const rnetwork::Endpoint &endpoint);

#endif //CPP_RTYPE_ENDPOINT_HPP
