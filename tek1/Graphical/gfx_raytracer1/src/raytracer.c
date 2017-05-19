/*
** raytracer.c for raytracer in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sun Mar  6 18:02:27 2016 Gauthier Cler
** Last update Sun Mar 13 18:50:44 2016 Gauthier Cler
*/

#include		"raytracer.h"

unsigned int	       	ajust_color(t_prog *prog, t_vec *vec)
{
  t_vec			res;
  t_color      		color;
  double		coef;

  res.x = prog->lum.x - prog->point.x;
  res.y = prog->lum.y - prog->point.y;
  res.z = prog->lum.z - prog->point.z;
  coef = norme(&res);
  apply_norme(&res, coef);
  coef = norme(vec);
  apply_norme(vec, coef);
  color.full = get_coef(prog, vec, &res, &coef);
  if (coef > 0 && prog->options.shadow == true)
    prevent_overflow(coef, &color);
  return (color.full);
}

void			display_back(t_prog *prog, double x, double y)
{
  t_bunny_position	pos;
  t_color		color;

  pos.x = x;
  pos.y = y;
  color.full = BLACK;
  tekpixel(prog->pix, &pos, &color);
}

void			display_elem(t_prog *prog, double x, double y, t_vec *vec)
{
  t_bunny_position	pos;
  t_color		color;

  color.full = ajust_color(prog, vec);
  pos.x = x;
  pos.y = y;
  tekpixel(prog->pix, &pos, &color);
}

void			ray_tracing(t_prog *prog, t_vec vec, double x, double y)
{
  int			i;

  prog->target.distance = 20000.0;
  i = 0;
  while (i < prog->nb_objects)
    {
      if (prog->object[i].type == 1)
	sphere_intersection(prog, &vec, &prog->eye_ori, i);
      if (prog->object[i].type == 2 && prog->options.plane == true)
	plane_intersection(prog, &vec, &prog->eye_ori, i);
      if (prog->object[i].type == 3)
	cylinder_intersection(prog, &vec, &prog->eye_ori, i);
      i += 1;
    }
  if (prog->target.distance == 20000)
    display_back(prog, x, y);
  else
    display_elem(prog, x, y, &vec);
}

void			calc_ray(double x, double y, t_prog *prog)
{
  t_vec			vec;

  vec.x = x - prog->pix->clipable.buffer.width / 2;
  vec.y = prog->pix->clipable.buffer.height / 2 - y;
  vec.z = 1000.0;
  ray_tracing(prog, vec, x, y);
}
