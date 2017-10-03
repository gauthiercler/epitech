/*
** new.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/map/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon Jun 26 08:34:32 2017 Antoine FORET
** Last update Mon Jun 26 08:34:32 2017 Antoine FORET
*/

#include	<malloc.h>
#include	<string.h>
#include	"map.h"

static void	map_methods(t_map *self)
{
  self->convert = map_convert;
  self->get_tile_by_position = map_get_tile_by_position;
  self->get_tile_by_player = map_get_tile_by_player;
  self->move = map_move;
  self->add_player = map_add_player;
  self->remove_player = map_remove_player;
  self->take = map_take;
  self->drop = map_drop;
  self->direction = map_direction;
  self->spawn_resources = map_spawn_resources;
  self->destroy = map_destroy;
}

static void	destroy_tiles(t_tile **tiles, size_t map_size)
{
  unsigned int	idx;

  idx = 0;
  while (idx < map_size)
  {
    if (tiles[idx] != NULL)
      tiles[idx]->destroy(tiles[idx]);
    idx += 1;
  }
}

static t_tile	**new_tiles(size_t width, size_t height)
{
  t_tile	**tiles;
  unsigned int	idx;
  size_t	map_size;

  idx = 0;
  map_size = width * height;
  tiles = malloc(sizeof(t_tile *) * map_size);
  if (tiles == NULL)
    return (NULL);
  memset(tiles, 0, sizeof(t_tile *) * map_size);
  while (idx < map_size)
  {
    tiles[idx] = new_tile();
    if (tiles[idx] == NULL)
    {
      destroy_tiles(tiles, map_size);
      return (NULL);
    }
    idx += 1;
  }
  return (tiles);
}

static bool	map_init(t_map *self, size_t width, size_t height)
{
  self->width = width;
  self->height = height;
  self->players = new_player_list();
  self->tiles = new_tiles(width, height);
  if (self->players == NULL || self->tiles == NULL)
    return (false);
  else
    return (true);
}

t_map		*new_map(size_t width, size_t height)
{
  t_map		*self;

  self = malloc(sizeof(t_map));
  if (self == NULL)
    return (NULL);
  map_methods(self);
  if (!map_init(self, width, height))
  {
    self->destroy(self);
    return (NULL);
  }
  return (self);
}