/*
** tekcircle.c for tekcircle in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan 26 21:46:30 2016 Gauthier Cler
** Last update Tue Jan 26 21:46:32 2016 Gauthier Cler
*/

#include		"tekpaint.h"

void			tekcircle(t_bunny_pixelarray		*pix,
				  const t_bunny_position	*pos,
				  double			radius,
				  t_color			*color)
{
  t_bunny_position	res[1];
  double		i;

  i = 0;
  while (i < 360)
    {
      res[0].x = cos(i) * radius + pos[0].x;
      res[0].y = sin(i) * radius + pos[0].y;
      tekpixel(pix, res, color);
      i += 0.01;
    }
}
