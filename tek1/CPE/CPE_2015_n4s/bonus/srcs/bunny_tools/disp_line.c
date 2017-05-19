/*
** disp_line.c for disp_line in /home/montag_v/rendu/CPE_2015_n4s/bonus
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Wed May 25 17:41:40 2016 montag_v
** Last update Wed May 25 23:53:21 2016 Gauthier Cler
*/

#include		"ia.h"

void			disp_line(t_raycast *ray,
				  int x,
				  float size)
{
  t_bunny_position	pos[2];
  t_color		color;
  int			length;

  color.full = RED;
  if (size >= 1800)
    color.argb[0] = 100;
  else
    color.argb[0] -= size / 12;
  size /= 500;
  length = ray->pix->clipable.buffer.height / size;
  pos[0].x = x;
  pos[1].x = x;
  pos[0].y = -length / 2 + ray->pix->clipable.buffer.height / 2;
  pos[1].y = length / 2 + ray->pix->clipable.buffer.height / 2;
  tekline(ray->pix, pos, &color.full);
}
