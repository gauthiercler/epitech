/*
** invert_color.c for invert_color in /tmp/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar  1 21:02:04 2016 Gauthier Cler
** Last update Tue Mar  1 22:30:08 2016 Gauthier Cler
*/

#include	"tekgui.h"

void		invert_and_display(t_prog *prog, int pos)
{
  int		*pixel;
  int		i;
  t_color	color[2];

  pixel = (int *)prog->gui[pos].pix->pixels;
  i = 0;
  while (i < prog->gui[pos].pix->clipable.buffer.width
	 * prog->gui[pos].pix->clipable.buffer.height)
    {
      color[0].full = pixel[i];
      color[1].argb[0] = color[0].argb[0];
      color[0].argb[0] = color[0].argb[2];
      color[0].argb[2] = color[1].argb[0];
      pixel[i] = color[0].full;
      i += 1;
    }
  blit_to_pix(prog->pix, prog->gui[pos]);
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, 0);
  bunny_display(prog->win);
}

void		invert_color(t_prog *prog, int pos)
{
  char		*tmp;
  int		i;

  i = 0;
  tmp = prog->gui[pos].action;
  tmp += 7;
  while (prog->gui[i].name != NULL)
    {
      if (my_strcmp(tmp, prog->gui[i].name) == 1)
	if (my_strcmp(prog->gui[i].type, "picture") == 1)
	  invert_and_display(prog, i);
      i += 1;
    }
}
