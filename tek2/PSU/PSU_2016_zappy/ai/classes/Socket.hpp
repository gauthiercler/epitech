/*
** Socket.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/classes/Socket.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 19 21:27:50 2017 Gauthier Cler
** Last update Mon Jun 19 21:27:50 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_SOCKET_HPP
#define PSU_2016_ZAPPY_SOCKET_HPP

#include <boost/asio/ip/tcp.hpp>
#include	"Error.hpp"

namespace ai {

  class Socket {

  public:
    Socket(boost::asio::io_service &ioService);
    virtual ~Socket();

    boost::asio::ip::tcp::socket &get();

    void		connect(const std::string &host, const std::string &port);
    void		disconnect(void);

  private:
    boost::asio::ip::tcp::socket	_socket;
    boost::asio::ip::tcp::resolver	_resolver;
  };

}

#endif //PSU_2016_ZAPPY_SOCKET_HPP
