#ifndef CPP_RTYPE_ACCEPTOR_HPP
#define CPP_RTYPE_ACCEPTOR_HPP

#include "rnetwork/async/IOService.hpp"
#include "rnetwork/rnetwork.hpp"
#include "rnetwork/Endpoint.hpp"
#include "rnetwork/IAcceptor.hpp"
#include "config/Export.hpp"
#include "Client.hpp"

namespace rnetwork
{
    namespace tcp
    {
        class RNETWORK_API Acceptor : public IAcceptor, public std::enable_shared_from_this<Acceptor>
        {
        protected:
            rnetwork::async::IOService &_ioService;
            SOCKET _socket;

        public:
            Acceptor(rnetwork::async::IOService &ioService, const rnetwork::Endpoint &endpoint, unsigned int queueSize = 10);
            Acceptor(const Acceptor &acceptor) = delete;
            virtual ~Acceptor();

            std::shared_ptr<rnetwork::IClient> accept() const override; // TODO try to put back return of rnetwork::tcp::Client
            std::shared_ptr<rnetwork::IClient> accept(bool &status) const override;
            void async_accept(const std::function<void (std::shared_ptr<rnetwork::IClient> client, bool status)> &callback) override;

            SOCKET socket() const override;

            rnetwork::async::IOService &ioService();

            Acceptor &operator=(const Acceptor &acceptor) = delete;

        private:
            bool bind(const rnetwork::Endpoint &endpoint) const;
            bool listen(unsigned int queueSize) const;
        };
    }
}


#endif //CPP_RTYPE_ACCEPTOR_HPP
