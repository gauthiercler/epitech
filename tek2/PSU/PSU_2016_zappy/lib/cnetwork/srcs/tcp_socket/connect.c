/*
** connect.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/tcp_socket/connect.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 10:49:28 2017 Antoine FORET
** Last update Thu Apr 27 10:49:28 2017 Antoine FORET
*/

#include		<memory.h>
#include		"tcp_socket.h"

bool			tcp_socket_connect(t_tcp_socket *self,
					       const char *host,
					       uint16_t port)
{
  struct hostent	*hostinfo;
  SOCKADDR_IN		sockaddr_in;

  memset(&sockaddr_in, 0, sizeof(sockaddr_in));
  hostinfo = gethostbyname(host);
  if (hostinfo == NULL)
    return (false);
  sockaddr_in.sin_addr = *(IN_ADDR *)(hostinfo->h_addr);
  sockaddr_in.sin_port = htons(port);
  sockaddr_in.sin_family = AF_INET;
  if (connect(self->socket, (SOCKADDR *)&sockaddr_in,
	      sizeof(sockaddr_in)) == SOCKET_ERROR)
    return (false);
  else
  {
    self->connected = true;
    return (true);
  }
}