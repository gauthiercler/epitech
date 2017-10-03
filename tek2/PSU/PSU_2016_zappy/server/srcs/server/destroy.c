/*
** destroy.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/server/destroy.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 16:42:58 2017 Montagne Valentin
** Last update Mon Jun 26 16:42:59 2017 Montagne Valentin
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		"server.h"

static void		server_destroy_players(t_server *self)
{
  if (self->teams != NULL)
  {
    self->teams->empty(self->teams);
    self->teams->destroy(self->teams);
  }
  if (self->players != NULL)
  {
    self->players->empty(self->players);
    self->players->destroy(self->players);
  }
}

static void		server_destroy_gfx(t_server *self)
{
  if (self->gfx != NULL)
  {
    self->gfx->empty(self->gfx);
    self->gfx->destroy(self->gfx);
  }
}

static void		server_destroy_network(t_server *self)
{
  if (self->watcher != NULL)
    self->watcher->destroy(self->watcher);
  if (self->connection_queue != NULL)
  {
    self->connection_queue->empty(self->connection_queue);
    self->connection_queue->destroy(self->connection_queue);
  }
}

void			server_destroy(t_server *self)
{
  fprintf(stderr, "[INFO] Stopping server.\n");
  if (self->socket_ai != NULL)
    self->socket_ai->destroy(self->socket_ai);
  if (self->socket_gfx != NULL)
    self->socket_gfx->destroy(self->socket_gfx);
  if (self->map != NULL)
    self->map->destroy(self->map);
  server_destroy_players(self);
  if (self->chrono != NULL)
    self->chrono->destroy(self->chrono);
  if (self->parser != NULL)
    self->parser->destroy(self->parser);
  server_destroy_network(self);
  if (self->config.team_names != NULL)
    free(self->config.team_names);
  server_destroy_gfx(self);
  free(self);
}