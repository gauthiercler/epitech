/*
** draw_level.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/drawing/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Apr 14 13:14:37 2016 Buyumad Anas
** Last update Sun Apr 17 20:14:17 2016 Gauthier Cler
*/

#include	"adventure.h"

int		draw_level(t_adventure *adventure, t_level *level)
{
  int		i;

  i = NB_DECOR - 1;
  while (i >= 0)
    {
      draw_decor(adventure, &level->decors[i]);
      i -= 1;
      if (i == 0)
	draw_character(adventure);
    }
  return (SUCCESS);
}
