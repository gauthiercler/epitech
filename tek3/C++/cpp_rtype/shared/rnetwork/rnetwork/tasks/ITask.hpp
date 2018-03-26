#pragma once

#include "rnetwork/services/IService.hpp"
#include "config/Export.hpp"

namespace rnetwork
{
    namespace tasks
    {
        class RNETWORK_API ITask
        {
        public:
            virtual bool available() const = 0;
            virtual void operator()() = 0;
            virtual void registerService() const = 0;
            virtual void unregisterService() const = 0;
            virtual rnetwork::services::IService &service() const = 0;
        };
    }
}
