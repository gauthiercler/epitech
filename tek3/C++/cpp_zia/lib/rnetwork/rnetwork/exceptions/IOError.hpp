#ifndef CPP_RTYPE_IOERROR_HPP
#define CPP_RTYPE_IOERROR_HPP

#include <stdexcept>
#include "config/Export.hpp"

namespace rnetwork
{
    namespace exceptions
    {
        class RNETWORK_API IOError : public std::runtime_error
        {
        public:
            explicit IOError(const std::string &what);
            IOError(const IOError &ioError) = default;
            ~IOError() override = default;

            IOError &operator=(const IOError &ioError) = default;
        };
    }
}


#endif //CPP_RTYPE_IOERROR_HPP
