/*
** disconect.c for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cnetwork/srcs/tcp_socket/disconect.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat May 13 22:15:24 2017 Antoine FORET
** Last update Sat May 13 22:15:24 2017 Antoine FORET
*/

#include	"tcp_socket.h"

void		tcp_socket_disconnect(t_tcp_socket *self)
{
  if (self->socket != -1)
  {
    closesocket(self->socket);
    self->socket = -1;
    self->connected = false;
  }
}