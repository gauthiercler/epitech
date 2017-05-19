/*
** intersection.c for intersection in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sun Mar  6 21:52:39 2016 Gauthier Cler
** Last update Wed Mar 16 08:07:32 2016 Gauthier Cler
*/

#include	<stdio.h>
#include	"raytracer.h"

double			find_res(t_vec calc, double delta)
{
  double		t1;
  double		t2;

  if (delta < 0)
    return (-1);
  t1 = (-calc.y - sqrt(delta)) / (2 * calc.x);
  t2 = (-calc.y + sqrt(delta)) / (2 * calc.x);
  if (t1 < 0 && t2 < 0)
    return (-1);
  else if (t1 < t2 && t1 >= 0)
    return (t1);
  else if (t2 > 0)
    return (t2);
  else
    return (-1);

}

void			cylinder_intersection(t_prog *prog,
					      t_vec *vec, t_vec *eye_ori, int i)
{
  t_vec			calc;
  double		delta;
  double		res;

  calc.x = pow(vec->x, 2) + pow(vec->z, 2);
  calc.y = 2 * ((eye_ori->x - prog->object[i].pos.x) * vec->x
		+ (eye_ori->z - prog->object[i].pos.z) * vec->z);
  calc.z = pow((eye_ori->x - prog->object[i].pos.x), 2)
    + pow((eye_ori->z - prog->object[i].pos.z), 2)
    - pow(prog->object[i].radius, 2);
  delta = pow(calc.y, 2) - (4 * calc.x * calc.z);
  res = find_res(calc, delta);
  if (res != -1 && res < prog->target.distance)
    {
      prog->point.x = eye_ori->x + vec->x * res;
      prog->point.y = eye_ori->y + vec->y * res;
      prog->point.z = eye_ori->z + vec->z * res;
      prog->target.distance = res;
      prog->target.elem = i;
    }
}

void			plane_intersection(t_prog *prog,
					   t_vec *vec, t_vec *eye_ori, int i)
{
  double		k;

  k = -1 * (eye_ori->y / vec->y);
  if (k > 0 && k < prog->target.distance)
    {
      prog->point.x = eye_ori->x + vec->x * k;
      prog->point.y = eye_ori->y + vec->y * k;
      prog->point.z = eye_ori->z + vec->z * k;
      prog->target.distance = k;
      prog->target.elem = i;
    }
}

void			sphere_intersection(t_prog *prog,
					    t_vec *vec, t_vec *eye_ori, int i)
{
  t_vec			calc;
  double		delta;
  double		res;

  calc.x = pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2);
  calc.y = 2 * ((eye_ori->x - prog->object[i].pos.x) * vec->x
		+ (eye_ori->y - prog->object[i].pos.y) * vec->y
		+ (eye_ori->z - prog->object[i].pos.z) * vec->z);
  calc.z = pow((eye_ori->x - prog->object[i].pos.x), 2)
    + pow((eye_ori->y - prog->object[i].pos.y), 2)
    + pow((eye_ori->z - prog->object[i].pos.z), 2)
    - pow(prog->object[i].radius, 2);
  delta = pow(calc.y, 2) - (4 * calc.x * calc.z);
  res = find_res(calc, delta);
  if (res != -1 && res < prog->target.distance)
    {
      prog->point.x = eye_ori->x + vec->x * res;
      prog->point.y = eye_ori->y + vec->y * res;
      prog->point.z = eye_ori->z + vec->z * res;
      prog->target.distance = res;
      prog->target.elem = i;
    }
}
