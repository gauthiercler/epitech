/*
** draw_form.c for draw_form in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 11 17:11:17 2016 Gauthier Cler
** Last update Tue Jan 26 21:24:17 2016 Gauthier Cler
*/

#include			"tekpaint.h"

int				circle(t_prog			*prog,
				       t_bunny_event_state	state,
				       t_bunny_mousebutton	key)

{
  int				i;
  double			rad;
  static t_bunny_position      	result[2];
  const t_bunny_position       	*pos;

  i = 0;
  if (key == BMB_LEFT && state == GO_DOWN)
    {
      pos = bunny_get_mouse_position();
      result[prog->palet.nb_clic].x = pos[0].x;
      result[prog->palet.nb_clic].y = pos[0].y;
      if (prog->palet.nb_clic == 1)
	{
	  rad = sqrt(pow((result[1].x - result[0].x), 2)
		     + pow((result[1].y - result[0].y), 2));
	  while (i++ < prog->palet.size)
	    tekcircle(prog->pix, result, rad - (double)i, prog->color);
	  prog->palet.nb_clic = 0;
	  return (GO_ON);
	}
      prog->palet.nb_clic = 1;
    }
  return (GO_ON);
}

void				draw_line(t_prog		*prog,
					  t_bunny_position	*result)
{
  int				i;

  i = 0;
  tekline(prog->pix, result, prog->color);
  while (i++ < prog->palet.size)
    {
      if (myabs(result[1].x - result[0].x) <= myabs(result[1].y - result[0].y))
	{
	  result[0].x += 1;
	  result[1].x += 1;
	  tekline(prog->pix, result, prog->color);
	  result[0].x -= 2;
	  result[1].x -= 2;
	  tekline(prog->pix, result, prog->color);
	}
      else
	{
	  result[0].y += 1;
	  result[1].y += 1;
	  tekline(prog->pix, result, prog->color);
	  result[0].y -= 2;
	  result[1].y -= 2;
	  tekline(prog->pix, result, prog->color);
	}
    }
}

int				line(t_prog			*prog,
				     t_bunny_event_state	state,
				     t_bunny_mousebutton	key)
{
  const t_bunny_position	*pos;
  static t_bunny_position	result[2];

  if (key == BMB_LEFT && state == GO_DOWN)
    {
      pos = bunny_get_mouse_position();
      result[prog->palet.nb_clic].x = pos[0].x;
      result[prog->palet.nb_clic].y = pos[0].y;
      if (prog->palet.nb_clic == 1)
	{
	  draw_line(prog, result);
	  prog->palet.nb_clic = 0;
	  return (GO_ON);
	}
      prog->palet.nb_clic += 1;
    }
  return (GO_ON);
}

int				myabs(int	nb)
{
  if (nb < 0)
    return (nb * -1);
  else
    return (nb);
}
