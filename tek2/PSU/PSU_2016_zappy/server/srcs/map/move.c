/*
** move.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/map/move.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon Jun 26 10:30:20 2017 Antoine FORET
** Last update Mon Jun 26 10:30:20 2017 Antoine FORET
*/

#include	"map.h"

bool		map_move(t_map *self, t_player *player, t_position *position)
{
  t_tile	*origin;
  t_tile	*target;

  origin = self->get_tile_by_player(self, player);
  target = self->get_tile_by_position(self, position);
  if (origin == NULL || target == NULL)
    return (false);
  if (!origin->remove_player(origin, player) ||
      !target->add_player(target, player))
    return (false);
  else
    return (true);
}