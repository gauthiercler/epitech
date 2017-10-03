/*
** remove_player.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/map/remove_player.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon Jun 26 22:17:00 2017 Antoine FORET
** Last update Mon Jun 26 22:17:00 2017 Antoine FORET
*/

#include	"map.h"

bool		map_remove_player(t_map *self, t_player *player)
{
  t_tile	*tile;

  tile = self->get_tile_by_player(self, player);
  if (tile == NULL)
    return (false);
  return (tile->remove_player(tile, player));
}