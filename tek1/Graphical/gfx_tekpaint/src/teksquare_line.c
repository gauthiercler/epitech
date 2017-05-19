/*
** teksquare_line.c for teksquare in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan 26 21:36:57 2016 Gauthier Cler
** Last update Tue Jan 26 21:37:00 2016 Gauthier Cler
*/

#include	"tekpaint.h"

void		compl_x(t_bunny_pixelarray	*pix,
			t_bunny_position	*pos,
			t_color			*color,
			int			*coef)
{
  int		i;
  int		j;
  int		add_x;
  int		add_y;

  i = 0;
  j = 0;
  add_x = 1;
  add_y = 1;
  if (pos[0].x > pos[1].x)
    add_x = -1;
  if (pos[0].y > pos[1].y)
    add_y = -1;
  while (i < coef[0])
    {
      pos[0].x += add_x;
      j += coef[1];
      if (j > coef[0])
	{
	  j -= coef[0];
	  pos[0].y += add_y;
	}
      tekpixel(pix, pos, color);
      i++;
    }
}

void		compl_y(t_bunny_pixelarray	*pix,
			t_bunny_position	*pos,
			t_color			*color,
			int			*coef)

{
  int		i;
  int		j;
  int		add_x;
  int		add_y;

  i = 0;
  j = 0;
  add_x = 1;
  add_y = 1;
  if (pos[0].x > pos[1].x)
    add_x = -1;
  if (pos[0].y > pos[1].y)
    add_y = -1;
  while (i < coef[1])
    {
      pos[0].y += add_y;
      j += coef[0];
      if (j > coef[0])
	{
	  j -= coef[1];
	  pos[0].x += add_x;
	}
      tekpixel(pix, pos, color);
      i++;
    }
}

void		teksquare_line(t_bunny_pixelarray	*pix,
			       t_bunny_position		*pos,
			       t_color			*color)
{
  int		coef[2];

  coef[0] = pos[1].x - pos[0].x;
  coef[1] = pos[1].y - pos[0].y;
  if (coef[0] < 0)
    coef[0] = coef[0] * -1;
  if (coef[1] < 0)
    coef[1] = coef[1] * -1;
  if (coef[0] > coef[1])
    compl_x(pix, pos, color, coef);
  else
    compl_y(pix, pos, color, coef);
}
