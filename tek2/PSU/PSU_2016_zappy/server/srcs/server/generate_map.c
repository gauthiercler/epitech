/*
** generate_map.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/generate_map.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 13:39:42 2017 Antoine FORET
** Last update Wed Jun 28 13:39:42 2017 Antoine FORET
*/

#include	<stdio.h>
#include	"server.h"

bool		server_generate_map(t_server *self)
{
  if (self->map != NULL)
    self->map->destroy(self->map);
  self->map = new_map(self->config.width, self->config.height);
  if (self->map == NULL)
  {
    fprintf(stderr, "[ERROR] Unable to allocate memory to store map.\n");
    return (false);
  }
  self->place_resources(self, self->config.spawn_per_tick);
  return (true);
}