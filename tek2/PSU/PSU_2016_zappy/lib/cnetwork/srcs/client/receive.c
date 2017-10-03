/*
** receive.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/client/receive.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 09:42:03 2017 Antoine FORET
** Last update Thu Apr 27 09:42:03 2017 Antoine FORET
*/

#include	"client.h"

ssize_t		tcp_client_receive(t_client *self, void *data,
					  size_t size, bool blocking)
{
  return (self->socket->receive(self->socket, data, size, blocking));
}