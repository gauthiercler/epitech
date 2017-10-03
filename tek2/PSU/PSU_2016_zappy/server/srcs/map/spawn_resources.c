/*
** spawn_resources.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/map/spawn_resources.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 11:11:10 2017 Antoine FORET
** Last update Wed Jun 28 11:11:10 2017 Antoine FORET
*/

#include	"map.h"

void		map_spawn_resources(t_map *self, t_config *config, float rate)
{
  unsigned int	idx;
  size_t	map_size;

  map_size = self->width * self->height;
  idx = 0;
  while (idx < map_size)
  {
    if (self->tiles[idx] != NULL)
      self->tiles[idx]->spawn(self->tiles[idx], config, rate);
    idx += 1;
  }
}