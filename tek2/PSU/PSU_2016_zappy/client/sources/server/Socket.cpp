/*
** Socket.cpp for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/client/sources/socket/Socket.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 16:26:55 2017 Montagne Valentin
** Last update Thu Jun 22 16:26:55 2017 Montagne Valentin
*/

#include			<string.h>
#include			<sys/socket.h>
#include <utils/Utils.hpp>
#include 			"utils/Error.hpp"
#include			"server/Socket.hpp"

zappy::Socket::Socket()
{
  this->_socket = socket(AF_INET, SOCK_STREAM, 0);
  this->_buffer = "";
  this->_connected = false;
  if (this->_socket == INVALID_SOCKET)
    throw zappy::SocketError("Error invalid Socket");
}

zappy::Socket::~Socket()
{
  if (this->_socket != -1) {
    closesocket(this->_socket);
  }
}

bool zappy::Socket::connectTo(const std::string &hostname, uint16_t port) {
  struct hostent	*hostinfo;
  SOCKADDR_IN		sockaddr_in;

  memset(&sockaddr_in, 0, sizeof(sockaddr_in));
  hostinfo = gethostbyname(hostname.c_str());
  if (hostinfo == NULL)
    return (false);
  sockaddr_in.sin_addr = *(IN_ADDR *)(hostinfo->h_addr);
  sockaddr_in.sin_port = htons(port);
  sockaddr_in.sin_family = AF_INET;
  if (connect(this->_socket, (SOCKADDR *)&sockaddr_in,
	      sizeof(sockaddr_in)) == SOCKET_ERROR)
    return (false);
  else
  {
    this->_connected = true;
    return (true);
  }
}

void zappy::Socket::disconnect(void) {
  if (this->_socket != -1)
  {
    closesocket(this->_socket);
    this->_socket = socket(AF_INET, SOCK_STREAM, 0);
    this->_buffer = "";
    this->_connected = false;
    if (this->_socket == INVALID_SOCKET)
      throw zappy::SocketError("Error invalid Socket");
  }
}

bool zappy::Socket::verifConnected() {
  int		error;
  socklen_t	size;

  error = 0;
  size = sizeof(error);
  if (getsockopt(this->_socket, SOL_SOCKET, SO_ERROR, &error, &size) != 0)
    return (false);
  else
    return (error == 0);
}

bool zappy::Socket::isConnected(void) {
  if (this->_connected && !this->verifConnected())
    this->_connected = false;
  return (this->_connected);
}

ssize_t zappy::Socket::send(const std::string &data, bool blocking) {
  ssize_t	written;
  int		flags;

  if (!this->_connected)
    return (SOCKET_ERROR);
  flags = ((blocking) ? 0 : MSG_DONTWAIT);
  written = ::send(this->_socket, data.c_str(), data.size(), flags);
  if (written == SOCKET_ERROR || written == 0)
  {
    this->_connected = false;
    return (0);
  }
  else
    return (written);
}

std::string zappy::Socket::receive(uint16_t size, bool blocking) {
  char		buff[size];
  ssize_t	received;
  int		flags;

  if (size == 0)
    return ("");
  memset(buff, 0, size);
  if (!this->_connected)
    return ("");
  flags = ((blocking) ? 0 : MSG_DONTWAIT);
  received = recv(this->_socket, reinterpret_cast<void *>(buff), size, flags);
  if (((received == SOCKET_ERROR || received == 0) && blocking) ||
      (!blocking && ((errno != EAGAIN && errno != EWOULDBLOCK) || received == 0)))
  {
    this->_connected = false;
    return ("");
  }
  else
    return (std::string(buff));
}

const std::string zappy::Socket::getIp(void) const {
  SOCKADDR_IN	info;
  unsigned int	info_size;

  info_size = sizeof(info);
  getsockname(this->_socket, (SOCKADDR *)(&info), &info_size);
  return (inet_ntoa(info.sin_addr));
}

uint16_t zappy::Socket::getPort(void) const {
  SOCKADDR_IN	info;
  unsigned int	info_size;

  info_size = sizeof(info);
  getsockname(this->_socket, (SOCKADDR*)(&info), &info_size);
  return (ntohs(info.sin_port));
}

const std::string zappy::Socket::getForeignIp(void) const {
  SOCKADDR_IN	info;
  unsigned int	info_size;

  info_size = sizeof(info);
  getpeername(this->_socket, (SOCKADDR *)(&info), &info_size);
  return (inet_ntoa(info.sin_addr));
}

bool zappy::Socket::enableKeepAlive(void) {
  int		value;
  socklen_t	size;

  value = 1;
  size = sizeof(value);
  return (setsockopt(this->_socket, SOL_SOCKET, SO_KEEPALIVE, &value, size) >= 0);
}

bool zappy::Socket::disableKeepAlive(void) {
  int		value;
  socklen_t	size;

  value = 0;
  size = sizeof(value);
  return (setsockopt(this->_socket, SOL_SOCKET, SO_KEEPALIVE, &value, size) >= 0);
}

bool zappy::Socket::keepAliveStatus(void) {
  int		status;
  socklen_t	size;

  size = sizeof(status);
  if (getsockopt(this->_socket, SOL_SOCKET, SO_KEEPALIVE, &status, &size) < 0)
    return (false);
  else
    return (status ? true : false);
}

