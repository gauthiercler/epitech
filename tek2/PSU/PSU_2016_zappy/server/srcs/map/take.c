/*
** take.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/map/take.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon Jun 26 11:24:11 2017 Antoine FORET
** Last update Mon Jun 26 11:24:11 2017 Antoine FORET
*/

#include	"map.h"

bool		map_take(t_map *self, t_position *position, t_ore ore)
{
  t_tile	*tile;

  tile = self->get_tile_by_position(self, position);
  if (tile == NULL)
    return (false);
  return (tile->add_ore(tile, ore));
}