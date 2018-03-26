#ifndef CPP_ZIA_CLIENT_HPP
#define CPP_ZIA_CLIENT_HPP

#include <rnetwork/tcp/Client.hpp>
#include <http.h>
#include "pp/module.hpp"
#include "shared/RequestBuilder.hpp"

namespace zia::modules::net {
  class Client : public std::enable_shared_from_this<Client>, public zia::api::ImplSocket {
  private:
    std::shared_ptr<rnetwork::IClient> _socket;
    zia::shared::RequestBuilder _requestBuilder;
    zia::api::Net::Callback _onReady{};

  public:
    explicit Client(std::shared_ptr<rnetwork::IClient> socket);
    Client(const Client &client) = delete;
    virtual ~Client() = default;

    void start();

    void onReady(zia::api::Net::Callback onReady);

    void sendMessage(std::string &) override;
    std::string receiveMessage() override;

    Client &operator=(const Client &client) = delete;

  private:
    void handleData(rnetwork::packet::PacketBase &packetBase, bool status);
    void ready();
    zia::api::NetInfo generateNetInfo() const;
  };
}

#endif //CPP_ZIA_CLIENT_HPP
