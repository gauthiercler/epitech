/*
** aa_computing.c for aa_computing in /home/gogo/rendu/gfx_raytracer2/srcs/threading/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun May 15 22:33:14 2016 Gauthier Cler
** Last update Sat May 21 12:55:23 2016 Gauthier Cler
*/

#include	"raytracer.h"

void		set_final_color(int *colors, t_color *final_color, int level)
{
  int		ratio;

  ratio = (2 * level + 1) * (2 * level + 1);
  final_color->argb[0] = colors[0] / ratio;
  final_color->argb[1] = colors[1] / ratio;
  final_color->argb[2] = colors[2] / ratio;
  final_color->argb[3] = 255;
}

void		blur_ray_compute(t_data *thread, int x, int y)
{
  thread->target.x += x;
  thread->target.y += y;
  compute_ray(&thread->origin, &thread->target, &thread->vector);
  thread->target.x -= x;
  thread->target.y -= y;
}
