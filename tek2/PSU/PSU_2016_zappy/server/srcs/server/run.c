/*
** run.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/run.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue Jun 27 19:37:35 2017 Antoine FORET
** Last update Tue Jun 27 19:37:35 2017 Antoine FORET
*/

#include	<stdio.h>
#include	"server.h"

static bool	initialized(t_server *self)
{
  if (self->map != NULL && self->socket_ai != NULL && self->socket_gfx != NULL)
    return (true);
  fprintf(stderr, "[ERROR] Server not initialized. Stopping\n");
  return (false);
}

static bool	send_gfx_map(t_graph_client *gfx, t_map *map)
{
  return (gfx->send_map(gfx, map));
}

bool		server_run(t_server *self)
{
  if (!initialized(self))
    return (false);
  self->running = true;
  printf("[INFO] Server running\n");
  while (self->running)
  {
    self->handle_network(self);
    self->tick(self);
    self->handle_connection_queue(self);
    self->handle_players(self);
    self->sync_gfx(self);
    if (self->tick_stack > self->config.spawn_delay)
    {
      fprintf(stderr, "[INFO] Spawn new resources.\n");
      self->place_resources(self, self->config.spawn_regular_rate);
      self->gfx->apply(self->gfx, (t_list_action)(send_gfx_map), self->map);
      self->tick_stack -= self->config.spawn_delay;
    }
  }
  return (true);
}

