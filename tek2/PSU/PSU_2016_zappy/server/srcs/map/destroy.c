/*
** destroy.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/map/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue Jun 27 15:57:08 2017 Antoine FORET
** Last update Tue Jun 27 15:57:08 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"map.h"

static void	delete_tiles(t_tile **tiles, size_t map_size)
{
  unsigned int	idx;

  idx = 0;
  while (idx < map_size)
  {
    if (tiles[idx] != NULL)
      tiles[idx]->destroy(tiles[idx]);
    idx += 1;
  }
  free(tiles);
}

void		map_destroy(t_map *self)
{
  if (self->tiles != NULL)
    delete_tiles(self->tiles, self->width * self->height);
  if (self->players != NULL)
    self->players->destroy(self->players);
  free(self);
}