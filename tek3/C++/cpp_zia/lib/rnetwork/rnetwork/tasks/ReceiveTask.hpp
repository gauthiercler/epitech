#ifndef CPP_RTYPE_RECEIVETASK_HPP
#define CPP_RTYPE_RECEIVETASK_HPP

#include "rnetwork/IReceiver.hpp"
#include "rnetwork/packet/PacketBase.hpp"
#include "rnetwork/services/NetworkService.hpp"
#include "config/Export.hpp"
#include "ITask.hpp"

namespace rnetwork
{
    namespace tasks
    {
        class RNETWORK_API ReceiveTask : public ITask
        {
        private:
            std::shared_ptr<rnetwork::IReceiver> _receiver;
            std::function<void (rnetwork::packet::PacketBase &packet, bool status)> _callback;

        public:
            ReceiveTask(std::shared_ptr<rnetwork::IReceiver> receiver, const std::function<void (rnetwork::packet::PacketBase &packet, bool status)> &callback);
            ReceiveTask(const ReceiveTask &receiveTask);
            virtual ~ReceiveTask()  = default;

            bool available() const override;

            void registerService() const override ;
            void unregisterService() const override ;

            rnetwork::services::NetworkService &service() const override ;

            void operator()() override;

            ReceiveTask &operator=(const ReceiveTask &receiveTask) = default;
        };
    }
}


#endif //CPP_RTYPE_RECEIVETASK_HPP
