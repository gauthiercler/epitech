/*
** hit_is_in_range.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/intersection/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun May 22 15:38:55 2016 Buyumad Anas
** Last update Sun May 22 15:39:22 2016 Buyumad Anas
*/

#include	"raytracer.h"

int		hit_is_in_range(float coeff, t_data *data,
				float center, float height)
{
  float		hit;

  hit = data->s_origin.y + (coeff * data->s_vector.y);
  if (hit < center || hit > center + height)
    return (ERROR);
  return (SUCCESS);
}
