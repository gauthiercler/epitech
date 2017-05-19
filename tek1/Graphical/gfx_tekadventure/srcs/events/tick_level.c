/*
** tick_level.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Apr 14 17:49:29 2016 Buyumad Anas
** Last update Fri Apr 15 14:30:40 2016 Buyumad Anas
*/

#include	"adventure.h"

int			tick_level(t_adventure *adventure, int mode)
{
  int			i;

  i = 0;
  if (mode == 1)
    adventure->main_pos -= 1;
  else if (mode == 2)
    adventure->main_pos += 1;
  while (i < NB_DECOR)
    {
      tick_decor(&adventure->levels[adventure->current_level].decors[i], mode);
      i += 1;
    }
  return (SUCCESS);
}
