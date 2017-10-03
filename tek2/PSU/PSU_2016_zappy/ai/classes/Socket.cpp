/*
** Socket.cpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/classes/Socket.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 19 21:28:28 2017 Gauthier Cler
** Last update Mon Jun 19 21:28:29 2017 Gauthier Cler
*/

#include <boost/asio/connect.hpp>
#include "Socket.hpp"

ai::Socket::Socket(boost::asio::io_service &ioService) :
  _socket(ioService),
  _resolver(ioService) {

}

ai::Socket::~Socket() {

}

boost::asio::ip::tcp::socket &ai::Socket::get() {
  return _socket;
}

void ai::Socket::connect(const std::string &host, const std::string &port) {
  boost::asio::ip::tcp::resolver::query query(host, port);

  auto endPoint = _resolver.resolve(query);
  _socket.connect(*endPoint);
}

void ai::Socket::disconnect(void) {
  _socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
  _socket.close();
}


