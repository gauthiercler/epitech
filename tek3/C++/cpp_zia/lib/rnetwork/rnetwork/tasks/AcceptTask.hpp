#ifndef CPP_RTYPE_ACCEPTTASK_HPP
#define CPP_RTYPE_ACCEPTTASK_HPP

#include "rnetwork/tcp/Acceptor.hpp"
#include "rnetwork/IAcceptor.hpp"
#include "rnetwork/services/NetworkService.hpp"

namespace rnetwork
{
    namespace tasks
    {
        class RNETWORK_API AcceptTask : public ITask
        {
        private:
            std::shared_ptr<rnetwork::IAcceptor> _acceptor;
            std::function<void (std::shared_ptr<rnetwork::IClient> client, bool status)> _callback;
        public:
            AcceptTask(std::shared_ptr<rnetwork::IAcceptor> acceptor, const std::function<void (std::shared_ptr<rnetwork::IClient> client, bool status)> &callback);
            AcceptTask(const AcceptTask &acceptTask) = default;
            virtual ~AcceptTask() = default;

            bool available() const override;

            void registerService() const override;
            void unregisterService() const override;

            rnetwork::services::NetworkService &service() const override;

            void operator()() override;

            AcceptTask &operator=(const AcceptTask &acceptTask) = default;
        };
    }
}


#endif //CPP_RTYPE_ACCEPTTASK_HPP
