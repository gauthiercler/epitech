/*
** receive.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/tcp_socket/receive.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 09:34:47 2017 Antoine FORET
** Last update Thu Apr 27 09:34:47 2017 Antoine FORET
*/

#include	"tcp_socket.h"

ssize_t		tcp_socket_receive(t_tcp_socket *self, void *data,
					  size_t size, bool blocking)
{
  ssize_t	received;
  int		flags;

  if (size == 0)
    return (0);
  if (self->connected == false)
    return (SOCKET_ERROR);
  flags = ((blocking) ? 0 : MSG_DONTWAIT);
  received = recv(self->socket, data, size, flags);
  if (received == SOCKET_ERROR || received == 0)
  {
    self->connected = false;
    return (SOCKET_ERROR);
  }
  else
    return (received);
}