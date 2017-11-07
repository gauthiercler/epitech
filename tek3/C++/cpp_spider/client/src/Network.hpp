/*
** Network.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/Network.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:15:58 2017 Gauthier Cler
** Last update Sun Oct 08 22:15:58 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_NETWORK_HPP
#define CPP_SPIDER_NETWORK_HPP

#include                    	<chrono>
#include <thread>
#include                    	"Spider/Network/Client/Client.hpp"
#include                  	"AOutStream.hpp"

#define                       	PINGTIMEOUT (20)

namespace 			Client {

  class 			Network : public AOutStream {

    using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

  public:

    enum class State {
      OK,
      WAITING,
      DISCONNECTED
    };

  private:

    Spider::Network::Client::instance _net;
    State _state;
    TimePoint _ping;
	  std::thread		_listenerThread;

    void handleData(std::string &&);
    bool isTimingOut();
    void sendPing();
    void listen();

  public:

    explicit Network(const std::string &name, CommunicationManager &cm, Client::AOutStream::StreamType type,
		     const std::string &ip, const unsigned short &port);
    ~Network() override;

    bool write(const std::string &data) override;
    bool isOpen() const override;
    bool isAlive() override;
    bool hasData() override;
    void clear() override;
    const std::string extractData() override;

  };
}

#endif //CPP_SPIDER_NETWORK_HPP
