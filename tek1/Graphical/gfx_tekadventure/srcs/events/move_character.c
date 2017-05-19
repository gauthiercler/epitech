/*
** move_character.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Apr 14 18:03:40 2016 Buyumad Anas
** Last update Sun Apr 17 19:50:22 2016 Gauthier Cler
*/

#include	"adventure.h"

void		set_moving_character(t_adventure *adventure,
				     const t_bunny_position *pos)
{
  int		delta;
  int		mode;

  if ((delta = calc_delta(&adventure->character, pos)) < 0)
    {
      delta = -delta;
      mode = 1;
    }
  else if (delta > 0)
    mode = 2;
  else
    return ;
  adventure->character.delta = delta;
  adventure->character.moving = true;
  adventure->character.current = 0;
  adventure->character.mode = mode;
  if ((pos->x < adventure->character.position.x)
      && ((adventure->main_pos - delta) < 0))
    adventure->character.moving_decor = false;
  else if ((pos->x > adventure->character.position.x)
	   && ((adventure->main_pos + delta) > 2000))
    adventure->character.moving_decor = false;
  else
    adventure->character.moving_decor = true;
  (adventure->character.moving_decor) ? adventure->character.blocked = true : 0;
}

void		move_character(t_adventure *adventure)
{
  if (adventure->character.moving_decor)
    tick_level(adventure, adventure->character.mode);
  adventure->character.current += 1;
  if ((!adventure->character.blocked)
      || (adventure->character.blocked
	  && (adventure->character.position.x < 475
	      || adventure->character.position.x > 475)))
    {
      if (adventure->character.mode == 1)
	adventure->character.position.x -= 1;
      else if (adventure->character.mode == 2)
	adventure->character.position.x += 1;
    }
  if (adventure->character.current >= adventure->character.delta)
    {
      adventure->character.current = 0;
      adventure->character.blocked = false;
      adventure->character.moving = false;
      adventure->character.moving_decor = true;
    }
}
