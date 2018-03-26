#ifndef CPP_RTYPE_INFINITETASK_HPP
#define CPP_RTYPE_INFINITETASK_HPP

#include "ITask.hpp"

namespace rnetwork
{
    namespace tasks
    {
        class InfiniteTask :  public ITask
        {
        private:

        public:
            InfiniteTask() = default;
            InfiniteTask(const InfiniteTask &infiniteTask) = default;
            virtual ~InfiniteTask() = default;

            bool available() const override;

            void registerService() const override;
            void unregisterService() const override;

            rnetwork::services::IService &service() const override;

            void operator()() override;

            InfiniteTask &operator=(const InfiniteTask &infiniteTask) = default;
        };
    }
}


#endif //CPP_RTYPE_INFINITETASK_HPP
