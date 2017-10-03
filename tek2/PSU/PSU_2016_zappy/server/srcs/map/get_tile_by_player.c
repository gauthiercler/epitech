/*
** get_tile_by_player.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/map/get_tile_by_player.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon Jun 26 11:28:05 2017 Antoine FORET
** Last update Mon Jun 26 11:28:05 2017 Antoine FORET
*/

#include	"map.h"

static t_tile	*search_player(t_map *self, t_player *player)
{
  t_position	position;
  unsigned int	idx;
  t_tile	*tile;
  size_t	map_size;

  idx = 0;
  map_size = self->width * self->height;
  while (idx < map_size)
  {
    position.x = (int)(idx % self->width);
    position.y = (int)(idx / self->width);
    tile = self->get_tile_by_position(self, &position);
    if (tile != NULL && tile->is_player_on(tile, player))
      return (tile);
    idx += 1;
  }
  return (NULL);
}

t_tile		*map_get_tile_by_player(t_map *self, t_player *player)
{
  t_tile	*tile;

  tile = self->get_tile_by_position(self, &player->position);
  if (tile != NULL && tile->is_player_on(tile, player))
    return (tile);
  else
    return (search_player(self, player));
}