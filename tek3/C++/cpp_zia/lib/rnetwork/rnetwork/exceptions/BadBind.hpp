#ifndef CPP_RTYPE_BADBIND_HPP
#define CPP_RTYPE_BADBIND_HPP

#include <stdexcept>
#include "config/Export.hpp"

namespace rnetwork
{
    namespace exceptions
    {
        class RNETWORK_API BadBind : public std::runtime_error
        {
        public:
            BadBind(const std::string &what);
            BadBind(const BadBind &badBind) = default;
            ~BadBind() override = default;

            BadBind &operator=(const BadBind &badBind) = default;
        };
    }
}


#endif //CPP_RTYPE_BADBIND_HPP
