/*
** receive_until.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/client/receive_until.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 09 16:48:14 2017 Antoine FORET
** Last update Tue May 09 16:48:14 2017 Antoine FORET
*/

#include	"client.h"

ssize_t		tcp_client_receive_until(t_client *self,
						char **data,
						const char *delimiter)
{
  return (self->socket->receive_until(self->socket, data, delimiter));
}