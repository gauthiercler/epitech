#ifndef CPP_RTYPE_NETWORKSERVICE_HPP
#define CPP_RTYPE_NETWORKSERVICE_HPP

#include <memory>
#include <deque>
#include <mutex>
#include <rnetwork/IAcceptor.hpp>
#include "rnetwork/IReceiver.hpp"
#include "rnetwork/ISender.hpp"
#include "IService.hpp"

namespace rnetwork
{
    namespace services
    {
        class RNETWORK_API NetworkService : public IService
        {
        public:
            static NetworkService& Instance();

        private:
            static NetworkService _instance;

        private:
            std::string _name;
            std::mutex _mutex;
            std::deque<std::shared_ptr<rnetwork::ISender>> _senders;
            std::deque<std::shared_ptr<rnetwork::IReceiver>> _receivers;
            std::deque<std::shared_ptr<rnetwork::IAcceptor>> _acceptors;
            fd_set _readFds;
            fd_set _writeFds;
            int _highestFd;

        public:
            NetworkService();
            NetworkService(const NetworkService &networkService) = delete;
            virtual ~NetworkService() = default;

            void update() override;
            const std::string &name() const override;

            void registerSender(std::shared_ptr<rnetwork::ISender> sender);
            void unregisterSender(std::shared_ptr<rnetwork::ISender> sender);

            void regiserReciver(std::shared_ptr<rnetwork::IReceiver> reciver);
            void unregisterReciver(std::shared_ptr<rnetwork::IReceiver> reciver);

            void registerAcceptor(std::shared_ptr<rnetwork::IAcceptor> acceptor);
            void unregisterAcceptor(std::shared_ptr<rnetwork::IAcceptor> acceptor);

            bool canSend(std::shared_ptr<const rnetwork::ISender> sender);
            bool canReceive(std::shared_ptr<const rnetwork::IReceiver> receiver);
            bool canAccept(std::shared_ptr<const rnetwork::IAcceptor> acceptor);

            NetworkService &operator=(const NetworkService &networkService) = delete;

        private:
            void updateFdSets();
        };
    }
}



#endif //CPP_RTYPE_NETWORKSERVICE_HPP
