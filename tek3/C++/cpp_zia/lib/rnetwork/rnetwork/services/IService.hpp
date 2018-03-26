#pragma once

#include <string>
#include "config/Export.hpp"

namespace rnetwork
{
    namespace services
    {
        class RNETWORK_API IService
        {
        public:
            virtual void update() = 0;
            virtual const std::string &name() const = 0;
        };

    }
}

bool operator==(const rnetwork::services::IService &a, const rnetwork::services::IService &b);