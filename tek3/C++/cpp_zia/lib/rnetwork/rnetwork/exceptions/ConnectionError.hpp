#ifndef CPP_RTYPE_CONNECTIONERROR_HPP
#define CPP_RTYPE_CONNECTIONERROR_HPP

#include <stdexcept>
#include "config/Export.hpp"

namespace rnetwork
{
    namespace exceptions
    {
        class RNETWORK_API ConnectionError : public std::runtime_error
        {
        private:

        public:
            ConnectionError(const std::string &what);
            ConnectionError(const ConnectionError &error) = default;
            ~ConnectionError() override = default;

            ConnectionError &operator=(const ConnectionError &error) = default;
        };
    }
}


#endif //CPP_RTYPE_CONNECTIONERROR_HPP
