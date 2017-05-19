/*
** draw_star.c for gfx_scroller in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/stars/draw_star.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar  19 13:26:42 2016 Anas Buyumad
** Last update Tue Mar 22 11:50:31 2016 Gauthier Cler
*/

#include		"megalovania.h"

void			draw_big(t_bunny_pixelarray *pix, t_star *star)
{
  t_bunny_position	pos;

  pos = star->pos;
  draw_square(pix, &pos, 12, star->color.full);
  pos.y -= 5;
  draw_square(pix, &pos, 12, star->color.full);
  pos.y += 10;
  draw_square(pix, &pos, 12, star->color.full);
  pos.x -= 5;
  pos.y -= 5;
  draw_square(pix, &pos, 12, star->color.full);
  pos.x += 10;
  draw_square(pix, &pos, 12, star->color.full);
}

void			draw_shooting(t_bunny_pixelarray *pix, t_star *star)
{
  t_bunny_position	pos;

  pos = star->pos;
  draw_square(pix, &star->pos, 2, star->color.full);
  pos.x -= 1;
  draw_square(pix, &star->pos, 2, star->color.full);
  pos.x -= 1;
  draw_square(pix, &star->pos, 2, star->color.full);
  pos.x -= 1;
  draw_square(pix, &star->pos, 2, star->color.full);
  pos.x -= 1;
  draw_square(pix, &star->pos, 2, star->color.full);
}

void	draw_star(t_bunny_pixelarray *pix, t_star *star)
{
  if (star->type == 1)
    draw_square(pix, &star->pos, 3, star->color.full);
  else if (star->type == 2)
    draw_square(pix, &star->pos, 10, star->color.full);
  else if (star->type == 3)
    draw_big(pix, star);
  else if (star->type == 4)
    draw_shooting(pix, star);
}
