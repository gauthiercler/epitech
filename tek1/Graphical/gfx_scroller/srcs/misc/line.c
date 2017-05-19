/*
** line.c for gfx_scroller in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/misc/line.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar  19 13:23:01 2016 Anas Buyumad
** Last update Tue Mar 22 11:48:19 2016 Gauthier Cler
*/

#include		"megalovania.h"

void			gradient(t_color *colors, t_color *final, float ratio)
{
  final->argb[0] =
    (uint8_t)(colors[1].argb[0] * ratio + colors[0].argb[0] * (1 - ratio));
  final->argb[1] =
    (uint8_t)(colors[1].argb[1] * ratio + colors[0].argb[1] * (1 - ratio));
  final->argb[2] =
    (uint8_t)(colors[1].argb[2] * ratio + colors[0].argb[2] * (1 - ratio));
  final->argb[3] =
    (uint8_t)(colors[1].argb[3] * ratio + colors[0].argb[3] * (1 - ratio));
}

void			line(t_bunny_pixelarray *pix,
			     t_bunny_position *pos, t_color *color)
{
  float			i;
  float			delta[3];
  t_color		final;
  t_bunny_position	point;

  i = 0;
  delta[0] = pos[1].x - pos[0].x;
  delta[1] = pos[1].y - pos[0].y;
  delta[2] = (float)(sqrt(pow(delta[0], 2) + pow(delta[1], 2)));
  while (i <= delta[2])
    {
      point.x = (int)(pos[0].x + delta[0] * (i / delta[2]));
      point.y = (int)(pos[0].y + delta[1] * (i / delta[2]));
      gradient(color, &final, (i / delta[2]));
      pixel(pix, &point, &final);
      i += 0.5;
    }
}
