/*
** send.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/client/send.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 10:47:59 2017 Antoine FORET
** Last update Thu Apr 27 10:47:59 2017 Antoine FORET
*/

#include	"client.h"

ssize_t		tcp_client_send(t_client *self, void *data,
				       size_t size, bool blocking)
{
  return (self->socket->send(self->socket, data, size, blocking));
}