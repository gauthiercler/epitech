#ifndef CPP_SPIDER_NETWORK_CLIENT_HPP
# define CPP_SPIDER_NETWORK_CLIENT_HPP

#include <Network/Client/Client.hpp>
#include <iostream>

namespace Spider
{
  namespace Network
  {
    class Client : public std::enable_shared_from_this<Spider::Network::Client>
    {
    public:
      using instance = std::shared_ptr<::Spider::Network::Client>;
      using dataCallback = std::function<void (std::string &&)>;
      using disconnectCallback = std::function<void (int)>;
      static Client::instance					connect(const std::string &host, unsigned short port, bool throwError = true);

    private:
      ::Network::Client::clientInstance		_client;
      std::string				_buff;
      dataCallback				_dataCallback;
      std::string				_mac;

    public:
      Client(::Network::Client::clientInstance client);
      virtual ~Client() = default;

      void					send(const std::string &data);
      void					syncSend(const std::string &data);
      void					listen();

      void					setDataCallback(dataCallback callback);
      void					setDisconnectCallback(disconnectCallback callback);

      void					setMac(const std::string &mac);
      const std::string				&getMac() const;

      void					defineCallbacks();

      void					disconnect();
    private:
      void					handleData(std::string &&data);
      long int					getJsonSize();
      void					handleWrite(bool &&) const;

    };
  }
}


#endif //CPP_SPIDER_CLIENT_HPP
