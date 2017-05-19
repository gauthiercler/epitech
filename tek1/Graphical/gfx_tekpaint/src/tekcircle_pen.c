/*
** tekcircle.c for tekcircle in /home/cler_g/rendu/liblapin
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
**
** Started on  Wed Dec  2 10:33:04 2015 Gauthier Cler
** Last update Tue Jan 26 21:34:56 2016 Gauthier Cler
*/

#include		"tekpaint.h"

void			tekcircle_pen(t_bunny_pixelarray	*pix,
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
      i += 0.08;
    }
}
