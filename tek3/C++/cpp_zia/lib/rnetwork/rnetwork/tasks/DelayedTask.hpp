#ifndef CPP_RTYPE_DELAYEDTASK_HPP
#define CPP_RTYPE_DELAYEDTASK_HPP

#include <functional>
#include <chrono>
#include "rnetwork/tasks/ITask.hpp"
#include "config/Export.hpp"

namespace rnetwork
{
    namespace tasks
    {
        class RNETWORK_API DelayedTask : public ITask
        {
        private:
            std::function<void ()> _task;
            std::chrono::time_point<std::chrono::steady_clock> _start;
            unsigned long _timeout;

        public:
            DelayedTask(const std::function<void ()> &callback, unsigned long time);
            DelayedTask(const DelayedTask &delayedTask) = default;
            virtual ~DelayedTask() = default;

            bool available() const override;

            void registerService() const override;
            void unregisterService() const override;

            rnetwork::services::IService &service() const override;

            void operator()() override;

            DelayedTask &operator=(const DelayedTask &delayedTask) = default;
        };
    }
}


#endif //CPP_RTYPE_DELAYEDTASK_HPP
