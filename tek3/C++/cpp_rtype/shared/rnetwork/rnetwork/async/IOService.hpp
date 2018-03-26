#ifndef CPP_RTYPE_IOSERVICE_HPP
#define CPP_RTYPE_IOSERVICE_HPP

#include <deque>
#include <mutex>
#include <memory>
#include <iostream>
#include "config/Export.hpp"
#include "rnetwork/services/IService.hpp"
#include "rnetwork/tasks/ITask.hpp"

namespace rnetwork
{
    namespace async
    {
        class RNETWORK_API IOService
        {
        private:
            std::deque<std::shared_ptr<rnetwork::tasks::ITask>> _tasks;
            std::deque<std::reference_wrapper<rnetwork::services::IService>> _services;
            std::mutex _taskMutex;
            std::mutex _serviceMutex;
            bool _run;

        public:
            IOService() = default;
            IOService(const IOService &ioService) = delete;
            virtual ~IOService() = default;

            void registerService(rnetwork::services::IService &service);
            void unregisterService(rnetwork::services::IService &service);

            void registerTask(std::shared_ptr<rnetwork::tasks::ITask> task);
            void unregisterTask(std::shared_ptr<rnetwork::tasks::ITask> task);

            void forceInfinite();

            void run();
            void stop();

            IOService &operator=(const IOService &ioService) = delete;

        private:
            void updateServices();
            bool execTasks();
        };
    }
}



#endif //CPP_RTYPE_IOSERVICE_HPP
