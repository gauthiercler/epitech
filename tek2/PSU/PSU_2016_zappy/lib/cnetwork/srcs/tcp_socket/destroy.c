/*
** destroy.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/tcp_socket/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 08:39:59 2017 Antoine FORET
** Last update Thu Apr 27 08:39:59 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"tcp_socket.h"

void		tcp_socket_destroy(t_tcp_socket *self)
{
  self->disconnect(self);
  if (self->buffer != NULL)
    free(self->buffer);
  free(self);
}