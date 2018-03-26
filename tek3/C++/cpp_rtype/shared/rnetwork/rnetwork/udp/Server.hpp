#ifndef CPP_RTYPE_SERVER_HPP
#define CPP_RTYPE_SERVER_HPP

#include "rnetwork/Endpoint.hpp"
#include "rnetwork/IReceiver.hpp"
#include "rnetwork/async/IOService.hpp"
#include "rnetwork/packet/PacketBase.hpp"
#include "rnetwork/rnetwork.hpp"
#include "config/Export.hpp"

namespace rnetwork
{
    namespace udp
    {
        class RNETWORK_API Server : public rnetwork::IReceiver, public std::enable_shared_from_this<Server>
        {
        private:
            rnetwork::async::IOService &_ioService;
            SOCKET _socket;

        public:
            explicit Server(rnetwork::async::IOService &ioService);
            Server(rnetwork::async::IOService &ioService, const rnetwork::Endpoint &endpoint);
            Server(const Server &server) = delete;
            virtual ~Server();

            std::shared_ptr<rnetwork::packet::PacketBase> receive(bool &status) override;
            std::shared_ptr<rnetwork::packet::PacketBase> receive() override;
            void async_receive(const std::function<void (rnetwork::packet::PacketBase &, bool status)> &callback);

            SOCKET socket() const override;
            rnetwork::async::IOService &ioService();

            bool bind(const rnetwork::Endpoint &endpoint);

            Server &operator=(const Server &server) = delete;
        };
    }
}


#endif //CPP_RTYPE_SERVER_HPP
