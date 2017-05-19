/*
** plane.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/intersection/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed May 11 17:29:07 2016 Buyumad Anas
** Last update Mon May 16 01:39:00 2016 Gauthier Cler
*/

#include	"raytracer.h"

static void	calculate_plane_polynomial(t_position *poly, t_data *data,
					      t_position *normal)
{
  poly->x = 0.0;
  poly->y = (normal->x * data->s_vector.x) + (normal->y * data->s_vector.y) +
      (normal->z * data->s_vector.z);
  poly->z = (normal->x * data->s_origin.x) + (normal->y * data->s_origin.y) +
      (normal->z * data->s_origin.z);
}

void		plane(t_data *data, t_infos *info, int index)
{
  t_position	polynomial;
  float		coeff;

  calculate_plane_polynomial(&polynomial, data, &info->normal);
  coeff = get_simple_root(polynomial.y, polynomial.z);
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
