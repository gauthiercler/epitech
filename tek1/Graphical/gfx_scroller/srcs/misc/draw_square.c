/*
** draw_square.c for gfx_scroller in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/misc/draw_square.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar  19 13:35:23 2016 Anas Buyumad
** Last update Sun Mar 20 14:25:06 2016 Anas Buyumad
*/

#include		"megalovania.h"

void			square_edge(t_bunny_pixelarray *pix,
				    t_bunny_position *pos,
				    unsigned int color_u,
				    double size)
{
  t_bunny_position	point[2];
  t_color		color[2];

  color[0].full = color_u;
  color[1].full = color_u;
  point[0].x = pos->x - size / 2;
  point[0].y = pos->y - size / 2;
  point[1].x = point[0].x + size;
  point[1].y = point[0].y;
  line(pix, point, color);
  point[0] = point[1];
  point[1].y += size;
  line(pix, point, color);
  point[0] = point[1];
  point[1].x -= size;
  line(pix, point, color);
  point[0] = point[1];
  point[1].y -= size;
  line(pix, point, color);
}
void			draw_square(t_bunny_pixelarray *pix,
				    t_bunny_position *pos,
				    double size, unsigned int color)
{
  while (size >= 0)
    {
      square_edge(pix, pos, color, size);
      size -= 1;
    }
}
