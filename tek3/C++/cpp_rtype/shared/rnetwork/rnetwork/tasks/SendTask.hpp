#ifndef CPP_RTYPE_SENDTASK_HPP
#define CPP_RTYPE_SENDTASK_HPP

#include <memory>
#include <functional>
#include "rnetwork/services/NetworkService.hpp"
#include "rnetwork/ISender.hpp"
#include "config/Export.hpp"
#include "ITask.hpp"

namespace rnetwork
{
    namespace tasks
    {
        class RNETWORK_API SendTask : public ITask, public std::enable_shared_from_this<SendTask>
        {
        private:
            std::function<void (bool)> _callback;
            std::shared_ptr<rnetwork::packet::IPacket> _packet;
            std::shared_ptr<rnetwork::ISender> _sender;

        public:
            SendTask(std::shared_ptr<rnetwork::ISender> sender, std::shared_ptr<rnetwork::packet::IPacket> packet, const std::function<void (bool)> &callback);
            SendTask(const SendTask &sendTask) = default;
            virtual ~SendTask() = default;

            bool available() const override;

            void registerService() const override;
            void unregisterService() const override;

            rnetwork::services::NetworkService &service() const override;

            void operator()() override;

            SendTask &operator=(const SendTask &sendTask) = default;
        };
    }
}


#endif //CPP_RTYPE_SENDTASK_HPP
