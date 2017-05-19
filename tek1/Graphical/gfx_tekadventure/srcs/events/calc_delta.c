/*
** calc_delta.c for calc_delta in /home/gogo/rendu/gfx_tekadventure/srcs/events
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 13 14:42:50 2016 Gauthier Cler
** Last update Sat Apr 16 21:25:12 2016 Gauthier Cler
*/

#include		"adventure.h"

int			calc_delta(t_character *character,
				   const t_bunny_position *pos)
{
  if (pos->y > character->position.y + character->size_y + 100
      || pos->y < character->position.y - 100)
    return (0);
  return (pos->x - character->position.x);
}
