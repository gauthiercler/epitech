/*
** events.c for events in /home/sylvain/Documents/zone_tests/Infographie/rush_incendie/gfx_incendie/version1/coucou
**
** Made by Sylvain Chaugny
** Login   <sylvain@epitech.net>
**
** Started on  Sun Dec  6 00:10:56 2015 Sylvain Chaugny
** Last update Sun Dec  6 19:07:58 2015 Sylvain Chaugny
*/

#include			<lapin.h>
#include			"include/my_flames.h"

t_bunny_response		key(t_bunny_event_state state,
				    t_bunny_keysym	key,
				    void                *data)
{
  t_prog			*prog;

  (void)state;
  prog = data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (key == BKS_UP && prog->plus < 50)
    prog->plus++;
  else if (key == BKS_DOWN && prog->plus > 0)
    prog->plus--;
  return (GO_ON);
}

t_bunny_response		click(t_bunny_event_state	state,
				      t_bunny_mousebutton	mouse,
				      void			*data)
{
  const t_bunny_position	*pos;
  t_prog			*prog;

  (void)mouse;
  prog = data;
  pos = bunny_get_mouse_position();
  if (pos->y > 730 - prog->plus * 2.5 && state == GO_DOWN)
    bunny_sound_play(prog->psit);
  return (GO_ON);
}

t_bunny_response		main_loop(void *p)
{
  t_prog			*prog;

  prog = p;

  fill_black(prog->pix);
  fire(prog->pix, prog->height, prog->plus);
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, &prog->pos);
  bunny_display(prog->win);
  return (GO_ON);
}
