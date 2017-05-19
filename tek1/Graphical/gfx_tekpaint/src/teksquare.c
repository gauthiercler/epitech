/*
** teksquare.c for teksquare in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan 26 21:46:08 2016 Gauthier Cler
** Last update Tue Jan 26 21:46:15 2016 Gauthier Cler
*/

#include		"tekpaint.h"

void			teksquare(t_bunny_pixelarray   		*pix,
				  const t_bunny_position	*pos,
				  t_color			*color,
				  int				size)
{
  int			i;
  t_bunny_position	carre[2];

  i = size;
  while (i > 0)
    {
      carre[0] = pos[0];
      carre[1].x = pos[0].x + i;
      carre[1].y = pos[0].y;
      teksquare_line(pix, carre, color);
      carre[0] = carre[0];
      carre[1].x = pos[0].x + i;
      carre[1].y = pos[0].y + i;
      teksquare_line(pix, carre, color);
      carre[0] = carre[1];
      carre[1].x = pos[0].x;
      carre[1].y = pos[0].y + i;
      teksquare_line(pix, carre, color);
      carre[0] = carre[1];
      carre[1].x = pos[0].x;
      carre[1].y = pos[0].y;
      teksquare_line(pix, carre, color);
      i--;
    }
}
