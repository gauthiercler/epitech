#ifndef CPP_RTYPE_ACCEPTERROR_HPP
#define CPP_RTYPE_ACCEPTERROR_HPP

#include <stdexcept>
#include "config/Export.hpp"

namespace rnetwork
{
    namespace exceptions
    {
        class RNETWORK_API AcceptError : public std::runtime_error
        {
        private:

        public:
            AcceptError(const std::string &what);
            AcceptError(const AcceptError &error) = default;
            ~AcceptError() override = default;

            AcceptError &operator=(const AcceptError &error) = default;
        };
    }
}


#endif //CPP_RTYPE_ACCEPTERROR_HPP
