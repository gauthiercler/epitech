/*
** polygon.c for polygon in /home/gogo/rendu/gfx_raytracer2/srcs/computation/intersection/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu May 12 23:51:12 2016 Gauthier Cler
** Last update Sun May 22 14:32:27 2016 Gauthier Cler
*/

#include		"raytracer.h"

static void		calculate_normal(t_position *normal,
					 t_position vector1,
					 t_position vector2)
{
  normal->x = vector2.y * vector1.z - vector2.z * vector1.y;
  normal->y = vector2.z * vector1.x - vector2.x * vector1.z;
  normal->z = vector2.x * vector1.y - vector2.y * vector1.x;
}

static void		do_vector_substraction(t_position *result,
					       t_position vector1,
					       t_position vector2)
{
  result->x = vector2.x - vector1.x;
  result->y = vector2.y - vector1.y;
  result->z = vector2.z - vector1.z;
}

static void		do_substracions(t_position *area, t_infos *info,
					int index)
{
  do_vector_substraction(&area[0], info->triangle[index].vector[1],
			 info->triangle[index].vector[0]);
  do_vector_substraction(&area[1], info->triangle[index].vector[2],
      			 info->triangle[index].vector[0]);
}

static int		do_one(t_data *data,
			       t_infos *info,
			       int index)
{
  t_position		area[2];
  t_position		plane;
  t_position		q;
  t_position		t;
  float			det;
  float			u;
  float			v;

  do_substracions(area, info, index);
  calculate_normal(&plane, data->s_vector, area[1]);
  det = area[0].x * plane.x + area[0].y * plane.y + area[0].z * plane.z;
  if (det > -0.000001 && det < 0.000001)
    return (ERROR);
  det = 1.f / det;
  do_vector_substraction(&t, data->origin, info->triangle[index].vector[0]);
  u = (t.x * plane.x + t.y * plane.y + t.z * plane.z) * det;
  if (u < 0.f || u > 1.f)
    return (ERROR);
  calculate_normal(&q, t, area[0]);
  v = (data->s_vector.x * q.x + data->s_vector.y * q.y + data->s_vector.z * q.z)
    * det;
  if (v < 0.f || v + u > 1.f)
    return (ERROR);
  data->coeff = (area[1].x * q.x + area[1].y * q.y + area[1].z * q.z) * det;
  return (SUCCESS);
}

void			polygon(t_data *data, t_infos *info, int index)
{
  int			i;

  i = 0;
  while (i < info->nb_triangle)
    {
      if (do_one(data, info, i) == SUCCESS)
	{
	  data->index = index;
	  data->polygon_index = i;
	}
      i += 1;
    }
}
