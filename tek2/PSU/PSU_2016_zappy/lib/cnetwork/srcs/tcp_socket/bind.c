/*
** bind.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/tcp_socket/bind.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 08:46:52 2017 Antoine FORET
** Last update Thu Apr 27 08:46:52 2017 Antoine FORET
*/

#include	<memory.h>
#include	"tcp_socket.h"

bool		tcp_socket_bind(t_tcp_socket *self, uint16_t port)
{
  SOCKADDR_IN	sockaddr_in;
  int		status;

  memset(&sockaddr_in, 0, sizeof(sockaddr_in));
  sockaddr_in.sin_addr.s_addr = htonl(INADDR_ANY);
  sockaddr_in.sin_family = AF_INET;
  sockaddr_in.sin_port = htons(port);
  status = bind(self->socket, (SOCKADDR *)&sockaddr_in, sizeof(sockaddr_in));
  if (status == SOCKET_ERROR)
    return (false);
  else
    return (true);
}