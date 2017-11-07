#ifndef SPIDER_CLIENT_HPP
#define SPIDER_CLIENT_HPP

#include <boost/function.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <queue>
#include <boost/asio/ssl/stream.hpp>

#define BUFF_SIZE	(512)

namespace Network
{
  class Client : public std::enable_shared_from_this<Network::Client>
  {
  public:

    using clientInstance = std::shared_ptr<Network::Client>;
    using readCallback = std::function<void (std::string &&)>;
    using writeCallback = std::function<void (bool &&)>;
    using disconnectCallback = std::function<void (int)>;
    using ssl_socket = boost::asio::ssl::stream<boost::asio::ip::tcp::socket>;

    static clientInstance				connect(const std::string &host, unsigned short port, bool throwError = true);

  private:
    ssl_socket						_socket;
    readCallback					_readCallback;
    writeCallback					_writeCallback;
    disconnectCallback					_disconnectCallback;
    boost::asio::io_service::strand			_readWrapper;
    boost::asio::io_service::strand			_writeWrapper;
    boost::array<char, BUFF_SIZE>			_buffer;
    std::queue<std::string>				_sendList;

  public:
    explicit Client(boost::asio::ssl::context &context, boost::asio::io_service &ioService);
    Client(const Client &client) = delete;
    virtual ~Client();

    void						setReceiveCallback(readCallback callback);
    void						setSendCallback(writeCallback callback);
    void						setDisconnectCallback(disconnectCallback callback);

    void						listen();
    void						send(const std::string &data);
    void						syncSend(const std::string &data);
    void						waitForData();
    void						disconnect();

    void						startTLS();

    ssl_socket::lowest_layer_type			&socket();


    Client						&operator=(const Client &client) = delete;

  private:
    void						listenData();
    void						handleData(const boost::system::error_code &ec, std::size_t size);

    void						sendData();
    void						sendDone(const boost::system::error_code &ec);

    void						handleHandshake(const boost::system::error_code &ec);
  };
}

#endif //SPIDER_CLIENT_HPP
