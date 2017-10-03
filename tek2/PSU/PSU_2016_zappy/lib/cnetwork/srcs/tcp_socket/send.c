/*
** send.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/tcp_socket/send.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 10:26:09 2017 Antoine FORET
** Last update Thu Apr 27 10:26:09 2017 Antoine FORET
*/

#include	"tcp_socket.h"

ssize_t		tcp_socket_send(t_tcp_socket *self, void *data,
				       size_t size, bool blocking)
{
  ssize_t	written;
  int		flags;

  if (self->connected == false)
    return (SOCKET_ERROR);
  flags = ((blocking) ? 0 : MSG_DONTWAIT);
  written = send(self->socket, data, size, flags);
  if (written == SOCKET_ERROR || written == 0)
  {
    self->connected = false;
    return (0);
  }
  else
    return (written);
}