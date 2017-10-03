/*
** add_player.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/map/add_player.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon Jun 26 13:39:10 2017 Antoine FORET
** Last update Mon Jun 26 13:39:10 2017 Antoine FORET
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"map.h"

static void	random_position(t_map *self, t_position *position)
{
  position->x = (int)(rand() % self->width);
  position->y = (int)(rand() % self->height);
}

static void	egg_position(t_egg *egg, t_position *position)
{
  position->x = egg->position.x;
  position->y = egg->position.y;
}

bool		map_add_player(t_map *self, t_player *player, t_egg *egg)
{
  t_tile	*tile;

  if (egg == NULL)
    random_position(self, &player->position);
  else
    egg_position(egg, &player->position);
  tile = self->get_tile_by_position(self, &player->position);
  if (tile == NULL)
    return (false);
  else
    return (tile->add_player(tile, player));
}