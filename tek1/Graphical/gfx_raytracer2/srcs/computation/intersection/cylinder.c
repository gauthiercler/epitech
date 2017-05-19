/*
** cylinder.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/intersection/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun May 22 15:16:37 2016 Buyumad Anas
** Last update Sun May 22 15:40:23 2016 Buyumad Anas
*/

#include	"raytracer.h"

static float	cylinder_head(t_data *data, t_infos *info, float eye_root,
			      float shadow_root)
{
  (void)data;
  (void)eye_root;
  info->cylinder_top = true;
  return (shadow_root);
}

static void	set_roots(float first_root, float second_root,
			  float *shadow_root, float *eye_root)
{
  if (first_root <= second_root)
    {
      *eye_root = first_root;
      *shadow_root = second_root;
    }
  else
    {
      *eye_root = second_root;
      *shadow_root = first_root;
    }
}

static float	get_cylinder_root(t_position *polynomial,
				  t_data *data, t_infos *info)
{
  float		delta;
  float		first_root;
  float		second_root;
  float		eye_root;
  float		shadow_root;

  if (polynomial->x == 0.0000)
    return (IMPOSSIBLE);
  delta = (polynomial->y * polynomial->y) -
      (4.0 * polynomial->x * polynomial->z);
  if (delta < 0.00000)
    return (IMPOSSIBLE);
  if (delta == 0.00000)
    return (((-1.0) * polynomial->y) / (2.0 * polynomial->x));
  first_root = (((-1.0) * polynomial->y) - sqrt(delta)) / (2.0 * polynomial->x);
  second_root = (((-1.0) * polynomial->y) + sqrt(delta)) /
      (2.0 * polynomial->x);
  set_roots(first_root, second_root, &shadow_root, &eye_root);
  if ((hit_is_in_range(eye_root, data,
		       info->center_y, info->height) == ERROR) &&
      (hit_is_in_range(shadow_root, data, info->center_y,
		       info->height) == SUCCESS))
    return (cylinder_head(data, info, eye_root, shadow_root));
  return (eye_root);
}

static void	calculate_cylinder_polynomial(t_position *poly, t_data *data,
					      float radius)
{
  poly->x = (data->s_vector.x * data->s_vector.x) +
      (data->s_vector.z * data->s_vector.z);
  poly->y = 2.0 * ((data->s_origin.x * data->s_vector.x) +
		   (data->s_origin.z * data->s_vector.z));
  poly->z = (data->s_origin.x * data->s_origin.x) +
      (data->s_origin.z * data->s_origin.z) - (radius * radius);
}

void		cylinder(t_data *data, t_infos *info, int index)
{
  t_position	polynomial;
  float		coeff;

  info->cylinder_top = false;
  calculate_cylinder_polynomial(&polynomial, data, info->radius);
  coeff = get_cylinder_root(&polynomial, data, info);
  if (coeff == IMPOSSIBLE)
    return ;
  if (coeff >= 0.00000)
    {
      if (hit_is_in_range(coeff, data, info->center_y, info->height) == ERROR)
	return ;
    }
  if (data->coeff < 0.00000 && coeff >= 0.00000)
    {
      data->coeff = coeff;
      data->index = index;
    }
  if (data->coeff >= 0.00000 && coeff < data->coeff && coeff >= 0.00000)
    {
      data->coeff = coeff;
      data->index = index;
    }
}
