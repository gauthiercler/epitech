/*
** menu_loop.c for menu_loop in /home/gogo/rendu/gfx_tekadventure/srcs/menu
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr 16 14:42:27 2016 Gauthier Cler
** Last update Sun Apr 17 16:31:13 2016 Gauthier Cler
*/

#include		"adventure.h"

void			blit_to_pos(t_bunny_buffer *buffer,
				    t_bunny_clipable *clipable, int x, int y)
{
  t_bunny_position	pos;

  pos.x = x;
  pos.y = y;
  bunny_blit(buffer, clipable, &pos);
}

void			set_scale(t_bunny_clipable *clipable, double size)
{
  clipable->scale.x = size;
  clipable->scale.y = size;
}

int			menu_loop(t_adventure *adventure)
{
  const t_bunny_position        *mouse;

  if (adventure->menu.play_music == true)
    {
      adventure->menu.play_music = false;
      bunny_sound_loop(&adventure->menu.music->sound, true);
      bunny_sound_play(&adventure->menu.music->sound);
    }
  mouse = bunny_get_mouse_position();
  if ((mouse->x <= 650 && mouse->x >= 400) && (mouse->y <= 400 && mouse->y >= 200))
    set_scale(adventure->menu.play, 1.1);
  else
    set_scale(adventure->menu.play, 1);
  if ((mouse->x <= 650 && mouse->x >= 400) && (mouse->y <= 600 && mouse->y >= 400))
    set_scale(adventure->menu.exit, 1.1);
  else
    set_scale(adventure->menu.exit, 1);
  blit_to_pos(&adventure->window->buffer, adventure->menu.bg, 0, 0);
  blit_to_pos(&adventure->window->buffer, adventure->menu.play, 400, 200);
  blit_to_pos(&adventure->window->buffer, adventure->menu.exit, 400, 400);
  return (SUCCESS);

}
