/*
** destroy.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/client/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 09:25:15 2017 Antoine FORET
** Last update Thu Apr 27 09:25:15 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"client.h"

void		tcp_client_destroy(t_client *self)
{
  if (self->socket != NULL)
    self->socket->destroy(self->socket);
  free(self);
}