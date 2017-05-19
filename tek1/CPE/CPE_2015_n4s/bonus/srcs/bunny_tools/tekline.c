/*
** tekline.c for tekline in /home/montag_v/rendu/lightning_2020
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Wed Dec  2 16:31:52 2015 valentin montagne
** Last update Fri May 27 00:59:28 2016 Gauthier Cler
*/

#include		<lapin.h>
#include		<math.h>
#include		"ia.h"
#include	       	"tekline.h"

void			draw(t_bunny_pixelarray *pix,
			     unsigned int color,
			     t_coo inc,
			     t_coo *coo)
{
  t_bunny_position	pos2;

  pos2.x = (int)coo->x;
  pos2.y = (int)coo->y;
  tekpixel(pix, &pos2, color);
  coo->x += inc.x;
  coo->y += inc.y;
}

void			tekline(t_bunny_pixelarray *pix, t_bunny_position *pos,
				unsigned int *color)
{
  t_coo			len;
  t_coo			inc;
  t_coo			coo;
  double		nb;
  int			i;

  coo.x = pos[0].x;
  coo.y = pos[0].y;
  len.x = pos[1].x - pos[0].x;
  len.y = pos[1].y - pos[0].y;
  nb = sqrt(len.x * len.x + len.y * len.y);
  inc.x = len.x / nb;
  inc.y = len.y / nb;
  i = 0;
  while (i < nb)
    {
      draw(pix, color[0], inc, &coo);
      i += 1;
    }
}
