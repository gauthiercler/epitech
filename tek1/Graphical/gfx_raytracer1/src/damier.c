/*
** damier.c for damier in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sat Mar 12 16:59:26 2016 Gauthier Cler
** Last update Sun Mar 13 21:20:06 2016 Gauthier Cler
*/

#include	"raytracer.h"

unsigned int	damier(t_prog *prog, t_vec *vec)
{
  t_vec		inter;
  double	res;
  double      	res2;
  double	size;

  size = 0.1;
  inter.x = prog->eye_ori.x + prog->target.distance * vec->x;
  inter.y = prog->eye_ori.y + prog->target.distance * vec->y;
  inter.z = prog->eye_ori.z + prog->target.distance * vec->z;
  res = sin(M_PI / size) * sin(inter.x * (prog->options.size * M_PI / size));
  res2 = sin(M_PI / size) * sin(inter.z * (prog->options.size * M_PI / size));
  if (res > 0 && res2 > 0)
    return (BLACK);
  else if (res > 0 && res2 < 0)
    return (prog->object[prog->target.elem].color.full);
  else if (res < 0 && res2 > 0)
    return (prog->object[prog->target.elem].color.full);
  else
    return (BLACK);
}
