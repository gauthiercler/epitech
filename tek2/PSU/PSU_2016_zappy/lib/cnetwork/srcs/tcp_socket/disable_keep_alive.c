/*
** disable_keep_alive.c for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cnetwork/srcs/tcp_socket/disable_keep_alive.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 29 13:19:19 2017 Antoine FORET
** Last update Mon May 29 13:19:19 2017 Antoine FORET
*/

#include	"tcp_socket.h"

bool		tcp_socket_disable_keep_alive(t_tcp_socket *self)
{
  int		value;
  socklen_t	size;

  value = 0;
  size = sizeof(value);
  if (setsockopt(self->socket, SOL_SOCKET, SO_KEEPALIVE, &value, size) < 0)
    return (false);
  else
    return (true);
}