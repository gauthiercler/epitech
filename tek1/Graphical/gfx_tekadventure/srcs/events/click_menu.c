/*
** click_menu.c for click_menu in /home/montag_v/rendu/gfx_tekadventure
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Fri Apr 15 15:02:07 2016 valentin montagne
** Last update Sat Apr 16 14:56:21 2016 Gauthier Cler
*/

#include		"adventure.h"

t_bunny_response	click_menu(t_bunny_event_state state,
				   t_bunny_mousebutton mouse,
				   void	*data)
{
  t_adventure			*adventure;
  const	t_bunny_position	*pos;

  adventure = data;
  pos = bunny_get_mouse_position();
  if (mouse == BMB_LEFT && state == GO_DOWN)
    {
      if ((pos->x <= 650 && pos->x >= 400) && (pos->y <= 400 && pos->y >= 200))
	adventure->current_level = 0;
      if ((pos->x <= 650 && pos->x >= 400) && (pos->y <= 600 && pos->y >= 400))
	return (EXIT_ON_SUCCESS);
    }
  return (GO_ON);
}
