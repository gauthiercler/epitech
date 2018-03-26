#ifndef CPP_ZIA_NET_HPP
#define CPP_ZIA_NET_HPP

#include <module.h>
#include <rnetwork/async/IOService.hpp>
#include <rnetwork/tcp/Acceptor.hpp>
#include <rnetwork/tcp/SSLAcceptor.hpp>
#include "Config.hpp"
#include "net.hpp"
#include "../../lib/rnetwork/rnetwork/IClient.hpp"

namespace zia::modules {

  class Net : public zia::api::Net {
  private:
      rnetwork::async::IOService _ioService;
      std::shared_ptr<rnetwork::tcp::Acceptor> _acceptor;
      std::shared_ptr<rnetwork::tcp::SSLAcceptor> _sslAcceptor;
      zia::api::Net::Callback _callback{};
      uint16_t _port {80};
      uint16_t _sslPort {443};
      uint16_t _nbThread {1};
      std::string _certPath;
      std::string _keyPath;

  public:
      Net() = default;

      ~Net() override = default;

      /**
      * Called after contruct and when config changed.
      * \return true on success, otherwise false.
      */
      bool config(const zia::api::Conf &conf) override;

      /**
      * Launch the server asynchronously, callback will be called when a request is received.
      * \return true on success, otherwise false
      */
      bool run(Callback cb) override;

      /**
      * Send a response.
      * \return true on success, otherwise false
      */
      bool send(zia::api::ImplSocket *sock, const Raw &resp) override;

      /**
      * Stop the server.
      * \return true on success, otherwise false
      */
      bool stop() override;

  private:
      void handleClient(std::shared_ptr<rnetwork::tcp::Acceptor> acceptor, std::shared_ptr<rnetwork::IClient> client, bool status);
      void start();
  };

  extern "C" MODULE_API zia::api::Net *create();

}

#endif //CPP_ZIA_NET_HPP
