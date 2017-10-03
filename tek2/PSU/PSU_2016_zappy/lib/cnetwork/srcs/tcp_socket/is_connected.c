/*
** is_connected.c for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cnetwork/srcs/tcp_socket/is_connected.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat May 13 22:25:01 2017 Antoine FORET
** Last update Sat May 13 22:25:01 2017 Antoine FORET
*/

#include	"tcp_socket.h"

bool		is_connected(t_tcp_socket *self)
{
  struct sockaddr_in	sockaddr_in;
  socklen_t		lenght;

  lenght = sizeof(sockaddr_in);
  if (getpeername(self->socket, (SOCKADDR*)(&sockaddr_in),
		  &lenght) == SOCKET_ERROR)
    return (false);
  else
    return (true);
}

bool		tcp_socket_is_connected(t_tcp_socket *self)
{
  if (self->connected && !is_connected(self))
    self->connected = false;
  return (self->connected);
}