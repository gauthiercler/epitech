/*
** keep_alive_status.c for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cnetwork/srcs/tcp_socket/keep_alive_status.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 29 13:15:41 2017 Antoine FORET
** Last update Mon May 29 13:15:41 2017 Antoine FORET
*/

#include	"tcp_socket.h"

bool		tcp_socket_keep_alive_status(t_tcp_socket *self)
{
  int		status;
  socklen_t	size;

  size = sizeof(status);
  if (getsockopt(self->socket, SOL_SOCKET, SO_KEEPALIVE, &status, &size) < 0)
    return (false);
  else
    return (status ? true : false);
}