/*
** get.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/map/get.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon Jun 26 10:24:55 2017 Antoine FORET
** Last update Mon Jun 26 10:24:55 2017 Antoine FORET
*/

#include	"map.h"

t_tile		*map_get_tile_by_position(t_map *self, t_position *position)
{
  t_position	real_position;
  size_t	position_idx;

  real_position.x = position->x;
  real_position.y = position->y;
  self->convert(self, &real_position);
  position_idx = real_position.x + real_position.y * self->width;
  if (position_idx >= self->width * self->height)
    return (NULL);
  else
    return (self->tiles[position_idx]);
}