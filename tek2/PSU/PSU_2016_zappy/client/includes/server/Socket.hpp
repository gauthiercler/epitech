/*
** Socket.hpp for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/client/includes/socket/Socket.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 16:01:39 2017 Montagne Valentin
** Last update Thu Jun 22 16:01:39 2017 Montagne Valentin
*/

#ifndef PSU_2016_ZAPPY_SOCKET_HPP
#define PSU_2016_ZAPPY_SOCKET_HPP

#include			<string>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<unistd.h>
#include		<netdb.h>

#  define		SOCKET		int
#  define		SOCKADDR_IN	struct sockaddr_in
#  define		SOCKADDR	struct sockaddr
#  define		IN_ADDR		struct in_addr

#  define		INVALID_SOCKET	(-1)
#  define		SOCKET_ERROR	(-1)
#  define		closesocket(s)	(close(s))

#  define		SOCK_INT(sock)	(sock)

namespace 			zappy
{

  class				Socket
  {
    SOCKET			_socket;
    std::string			_buffer;
    bool			_connected;

  public:

    Socket();
    ~Socket();

    // CONNECTION

    bool			connectTo(const std::string &hostname, uint16_t port);
    void			disconnect(void);
    bool			isConnected(void);

    // SEND / RECEIVE

    ssize_t 			send(const std::string &data, bool blocking = true);
    std::string 		receive(uint16_t size, bool blocking = true);

    // GETTERS

    const std::string 		getIp(void) const;
    uint16_t 			getPort(void) const;
    const std::string 		getForeignIp(void) const;

    // OPTIONS

    bool			enableKeepAlive(void);
    bool			disableKeepAlive(void);
    bool			keepAliveStatus(void);

  private:
    bool			verifConnected();
  };

}

#endif /* !PSU_2016_ZAPPY_SOCKET_HPP */
