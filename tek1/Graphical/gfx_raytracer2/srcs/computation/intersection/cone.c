/*
** cone.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/intersection/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed May 11 17:29:39 2016 Buyumad Anas
** Last update Sun May 22 15:43:51 2016 Buyumad Anas
*/

#include	"raytracer.h"

static int	hit_is_in_rangec(float coeff, t_data *data,
				 float center, float height)
{
  float		hit;

  return (SUCCESS);
  hit = data->s_origin.y + (coeff * data->s_vector.y);
  if (hit < center || hit > center + height)
    return (ERROR);
  return (SUCCESS);
}

static void	calculate_cone_polynomial(t_position *poly, t_data *data,
					      float angle)
{
  angle = (M_PI * angle) / 180.0;
  poly->x = (data->s_vector.x * data->s_vector.x) +
      (data->s_vector.z * data->s_vector.z) -
  ((data->s_vector.y * data->s_vector.y) *
       (tan(angle) * tan(angle)));
  poly->y = (2.0 * ((data->s_origin.x * data->s_vector.x) +
	     (data->s_origin.z * data->s_vector.z))) - (2.0 *
	     (data->s_origin.y * data->s_vector.y) *
	     (tan(angle) * tan(angle)));
  poly->z = (data->s_origin.x * data->s_origin.x) +
      (data->s_origin.z * data->s_origin.z) -
  (data->s_origin.y * data->s_origin.y *
       (tan(angle) * tan(angle)));
}

void		cone(t_data *data, t_infos *info, int index)
{
  t_position	polynomial;
  float		coeff;

  calculate_cone_polynomial(&polynomial, data, info->radius);
  coeff = get_root(polynomial.x, polynomial.y, polynomial.z);
  if (coeff == IMPOSSIBLE)
    return ;
  if (coeff >= 0.00000)
    {
      if (hit_is_in_rangec(coeff, data, info->center_y, info->height) == ERROR)
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
