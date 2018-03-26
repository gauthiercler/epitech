#ifndef CPP_RTYPE_BADLISTEN_HPP
#define CPP_RTYPE_BADLISTEN_HPP


#include <stdexcept>
#include "config/Export.hpp"

namespace rnetwork
{
    namespace exceptions
    {
        class RNETWORK_API BadListen : public std::runtime_error
        {
        private:

        public:
            BadListen(const std::string &what);
            BadListen(const BadListen &badListen) = default;
            ~BadListen() override = default;

            BadListen &operator=(const BadListen &badListen) = default;
        };
    }
}


#endif //CPP_RTYPE_BADLISTEN_HPP
