/*
** listen_gfx.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/listen_gfx.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 15:15:54 2017 Antoine FORET
** Last update Wed Jun 28 15:15:54 2017 Antoine FORET
*/

#include	<stdio.h>
#include	"server.h"

bool		server_listen_gfx(t_server *self)
{
  if (self->socket_gfx != NULL)
    self->socket_gfx->destroy(self->socket_gfx);
  self->socket_gfx = new_tcp_socket();
  if (self->socket_gfx == NULL)
  {
    fprintf(stderr, "[ERROR] Unable to create gfx socket.\n");
    return (false);
  }
  if (!self->socket_gfx->bind(self->socket_gfx, self->config.gfx_port) ||
      !self->socket_gfx->listen(self->socket_gfx, 5))
  {
    fprintf(stderr, "[ERROR] Unable to listen on port %d.\n",
	    self->config.gfx_port);
    self->socket_gfx->destroy(self->socket_gfx);
    self->socket_gfx = NULL;
    return (false);
  }
  fprintf(stderr, "[INFO] Listening on %s:%d for gfx.\n",
	  self->socket_gfx->get_ip(self->socket_gfx),
	  self->socket_gfx->get_port(self->socket_gfx));
  return (true);
}
