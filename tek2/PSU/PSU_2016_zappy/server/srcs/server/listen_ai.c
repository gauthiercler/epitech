/*
** listen_ai.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/listen_ai.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 15:05:41 2017 Antoine FORET
** Last update Wed Jun 28 15:05:41 2017 Antoine FORET
*/

#include	<stdio.h>
#include	"server.h"

bool		server_listen_ai(t_server *self)
{
  if (self->socket_ai != NULL)
    self->socket_ai->destroy(self->socket_ai);
  self->socket_ai = new_tcp_socket();
  if (self->socket_ai == NULL)
  {
    fprintf(stderr, "[ERROR] Unable to create ai socket.\n");
    return (false);
  }
  if (!self->socket_ai->bind(self->socket_ai, self->config.ai_port) ||
      !self->socket_ai->listen(self->socket_ai, 5))
  {
    fprintf(stderr, "[ERROR] Unable to listen on port %d.\n",
	    self->config.ai_port);
    self->socket_ai->destroy(self->socket_ai);
    self->socket_ai = NULL;
    return (false);
  }
  fprintf(stderr, "[INFO] Listening on %s:%d for ai.\n",
	  self->socket_ai->get_ip(self->socket_ai),
	  self->socket_ai->get_port(self->socket_ai));
  return (true);
}