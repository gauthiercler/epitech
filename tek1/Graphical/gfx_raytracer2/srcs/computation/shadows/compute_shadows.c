/*
** compute_shadows.c for raytracer in /home/gogo/rendu/gfx_raytracer2
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
**
** Started on  Fri May 20 16:18:01 2016 Gauthier Cler
** Last update Sun May 22 15:37:21 2016 Buyumad Anas
*/

#include	"raytracer.h"

static void	assess_position_light(t_data *data, t_position *object_pos,
				      t_position *inclinaison)
{
  data->s_origin.x = data->origin.x - object_pos->x;
  data->s_origin.y = data->origin.y - object_pos->y;
  data->s_origin.z = data->origin.z - object_pos->z;
  data->s_vector.x = data->vector.x;
  data->s_vector.y = data->vector.y;
  data->s_vector.z = data->vector.z;
  rotate_inverse(&data->s_origin, inclinaison);
  rotate_inverse(&data->s_vector, inclinaison);
}

static float	calculate_ratio(t_data *data, t_lux *lux, float lux_coeff)
{
  t_position	obstruction_pos;
  float		light_distance;
  float		distance;
  float		ratio;

  light_distance = sqrt(((lux->origin.x - data->origin.x) *
			 (lux->origin.x - data->origin.x)) +
  ((lux->origin.y - data->origin.y) * (lux->origin.y - data->origin.y)) +
  ((lux->origin.z - data->origin.z) * (lux->origin.z - data->origin.z)));
  obstruction_pos.x = data->origin.x + data->coeff * data->vector.x;
  obstruction_pos.y = data->origin.y + data->coeff * data->vector.y;
  obstruction_pos.z = data->origin.z + data->coeff * data->vector.z;
  distance = sqrt(((obstruction_pos.x - data->origin.x) *
		   (obstruction_pos.x - data->origin.x)) +
  ((obstruction_pos.y - data->origin.y) *
   (obstruction_pos.y - data->origin.y)) +
  ((obstruction_pos.z - data->origin.z) *
   (obstruction_pos.z - data->origin.z)));
  ratio = distance / light_distance;
  if (data->coeff > 0.00000 && data->coeff < lux_coeff)
    data->obstructed = true;
  else
    data->obstructed = false;
  return (ratio);
}

static float	compute_light_shadow(t_raytracer *raytracer, t_data *data,
				     t_lux *lux)
{
  int		hitpoint_index;
  float		lux_coeff;
  int		index;

  index = 0;
  hitpoint_index = data->index;
  data->coeff = -1.0;
  data->index = -1;
  lux_coeff = (lux->origin.y - data->origin.y) / data->vector.y;
  compute_space_ray(&data->origin, &lux->origin, &data->vector);
  while (index < raytracer->nb_obj)
    {
      assess_position_light(data, &raytracer->object[index].origin,
			    &raytracer->object[index].infos.inclinaison);
      raytracer->object[index].infos.center_y =
	  raytracer->object[index].origin.y;
      raytracer->object[index].infos.cylinder_top = false;
      if (index != hitpoint_index)
	raytracer->compute[raytracer->object[index].type]
      (data, &raytracer->object[index].infos, index);
      index += 1;
    }
  data->index = hitpoint_index;
  return (calculate_ratio(data, lux, lux_coeff));
}

int		compute_shadow(t_raytracer *raytracer, t_data *data)
{
  int		index;
  float		coeff;
  float		ratio;

  coeff = 0.0;
  index = 0;
  while (index < raytracer->nb_lux)
    {
      ratio = compute_light_shadow(raytracer, data, &raytracer->lux[index]);
      if (ratio < 0.0)
	ratio = (-1.0) * ratio;
      if (ratio >= 1.0)
	ratio = 1.0;
      coeff += ratio;
      index += 1;
    }
  coeff /= (float)index;
  data->shadow_coeff = coeff;
  return (SUCCESS);
}
