#ifndef CPP_RTYPE_BADHOSTNAME_HPP
#define CPP_RTYPE_BADHOSTNAME_HPP

#include <string>
#include <stdexcept>
#include "config/Export.hpp"

namespace rnetwork
{
    namespace exceptions
    {
        class RNETWORK_API BadHostname : public std::logic_error
        {
        private:

        public:
            explicit BadHostname(const std::string &hostname);
            BadHostname(const BadHostname &badHostname) = default;
            ~BadHostname() override = default;

            BadHostname &operator=(const BadHostname &badHostname) = default;
        };
    }
}


#endif //CPP_RTYPE_BADHOSTNAME_HPP
