/*
** draw_character.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/drawing/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Apr 14 23:28:08 2016 Buyumad Anas
** Last update Sun Apr 17 20:07:37 2016 Gauthier Cler
*/

#include	"adventure.h"

void		draw_sprite(t_sprite *sprite, int state)
{
  sprite->current_frame += 0.08;
  if (sprite->current_frame > sprite->nb_frame)
    sprite->current_frame = 1;
  if (state == 1)
    sprite->pix->clip_x_position = (int)sprite->current_frame * sprite->size;
  else
    sprite->pix->clip_x_position =
      (int)(sprite->nb_frame - sprite->current_frame - 1) * sprite->size;
  sprite->pix->clip_y_position = 0;
  sprite->pix->clip_height = sprite->pix->buffer.height;
  sprite->pix->clip_width = sprite->size;
}

void		call_draw_sprite(t_sprite *sprite, int state,
				 t_bunny_window *win, t_bunny_position *pos)
{
  draw_sprite(sprite, state);
  bunny_blit(&win->buffer, sprite->pix, pos);
}

int		draw_character(t_adventure *adventure)
{
  t_bunny_position	pos;

  pos.x = adventure->character.position.x;
  pos.y = adventure->character.position.y;
  if (adventure->character.moving == true
      && adventure->character.mode == 2)
    call_draw_sprite(&adventure->character.move_right, 1,
		     adventure->window, &pos);
  else if (adventure->character.moving == false
	   && adventure->character.mode == 2)
    call_draw_sprite(&adventure->character.stay_right, 1,
		     adventure->window, &pos);
  else if (adventure->character.moving == true
	   && adventure->character.mode == 1)
    call_draw_sprite(&adventure->character.move_left, 2,
		     adventure->window, &pos);
  else
    call_draw_sprite(&adventure->character.stay_left, 2,
		     adventure->window, &pos);
  return (SUCCESS);
}
