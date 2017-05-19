/*
** sphere.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/intersection/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed May 11 17:28:54 2016 Buyumad Anas
** Last update Sun May 22 15:38:18 2016 Buyumad Anas
*/

#include	"raytracer.h"

static float	calculate_sphere_polynomial(t_data *data, float radius)
{
  t_position	poly;

  poly.x = (data->s_vector.x * data->s_vector.x) +
      (data->s_vector.y * data->s_vector.y) +
    (data->s_vector.z * data->s_vector.z);
  poly.y = 2.0 * ((data->s_origin.x * data->s_vector.x) +
		   (data->s_origin.y * data->s_vector.y) +
		   (data->s_origin.z * data->s_vector.z));
  poly.z = (data->s_origin.x * data->s_origin.x) +
      (data->s_origin.y * data->s_origin.y) +
    (data->s_origin.z * data->s_origin.z) -
  (radius * radius);
  return (get_root(poly.x, poly.y, poly.z));
}

void		sphere(t_data *data, t_infos *info, int index)
{
  float		coeff;

  coeff = calculate_sphere_polynomial(data, info->radius);
  if (coeff == IMPOSSIBLE)
    return ;
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
