/*
** Server.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Network/Server/Server.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:43:08 2017 Gauthier Cler
** Last update Sun Oct 08 19:43:08 2017 Gauthier Cler
*/

#ifndef SPIDER_SERVER_HPP
#define SPIDER_SERVER_HPP

#include <boost/asio/io_service.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include "Network/Client/Client.hpp"

namespace Network
{
  class Server
  {

  public:

    using connectionCallback = std::function<void (Network::Client::clientInstance &&)>;
    using ssl_socket = boost::asio::ssl::stream<boost::asio::ip::tcp::socket>;


  private:
    bool				_started;
    boost::asio::io_service		_ioService;
    boost::asio::ip::tcp::acceptor	_acceptor;
    Network::Client::clientInstance	_client;
    boost::asio::ssl::context		_context;
    connectionCallback			_connectionCallback;

  public:
    Server();
    Server(const Server &server) = delete;
    virtual ~Server();

    void				start(const unsigned short port);
    void				setConnectionCallback(connectionCallback callback);

    Server				&operator=(const Server &server) = delete;

  private:
    void				listen(const unsigned short port);
    void				accept();
    void				handleConnection(const boost::system::error_code &ec);
    void				createClient();
    std::string				getPassword();
    void				defineContext();
  };
};



#endif //SPIDER_SERVER_HPP
