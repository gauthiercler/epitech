#ifndef CPP_RTYPE_EXECTASK_HPP
#define CPP_RTYPE_EXECTASK_HPP

#include <functional>
#include "config/Export.hpp"
#include "ITask.hpp"

namespace rnetwork
{
    namespace tasks
    {
        class RNETWORK_API ExecTask : public ITask
        {
        private:
            std::function<void ()> _task;

        public:
            explicit ExecTask(const std::function<void ()> &task);
            ExecTask(const ExecTask &execTask) = delete;
            virtual ~ExecTask() = default;

            bool available() const override;
            void operator()() override;
            void registerService() const override;
            void unregisterService() const override;

            rnetwork::services::IService &service() const override;

            ExecTask &operator=(const ExecTask &execTask) = delete;
        };
    }
}


#endif //CPP_RTYPE_EXECTASK_HPP
