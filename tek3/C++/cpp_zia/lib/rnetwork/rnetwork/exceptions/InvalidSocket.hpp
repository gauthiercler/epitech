#ifndef CPP_RTYPE_INVALIDSOCKET_HPP
#define CPP_RTYPE_INVALIDSOCKET_HPP

#include <string>
#include <stdexcept>
#include "config/Export.hpp"

namespace rnetwork
{
    namespace exceptions
    {
        class RNETWORK_API InvalidSocket : public std::runtime_error
        {
        public:
            explicit InvalidSocket(const std::string &what);
            InvalidSocket(const InvalidSocket &invalidSocket) = default;
            ~InvalidSocket() override = default;

            InvalidSocket &operator=(const InvalidSocket &invalidSocket) = default;
        };
    }
}


#endif //CPP_RTYPE_INVALIDSOCKET_HPP
