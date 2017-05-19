/*
** compute_light.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/light/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri May 20 16:40:34 2016 Buyumad Anas
** Last update Sun May 22 16:09:35 2016 Buyumad Anas
*/

#include	"raytracer.h"

static void	set_real_data(t_position *real_rotation,
			      t_position *simple_hitpoint,
			      t_data *data, t_object *object)
{
  simple_hitpoint->x = data->hitpoint.x;
  simple_hitpoint->y = data->hitpoint.y;
  simple_hitpoint->z = data->hitpoint.z;
  real_rotation->x = object->infos.inclinaison.x * (-1.0);
  real_rotation->y = object->infos.inclinaison.y * (-1.0);
  real_rotation->z = object->infos.inclinaison.z * (-1.0);
  rotate_inverse(simple_hitpoint, real_rotation);
  if (object->type == POLYGON)
    {

    }
}

static void	compute_object_normal(t_object *object, t_data *data,
				      t_position *object_normal)
{
  t_position	real_rotation;
  t_position	simple_hitpoint;

  set_real_data(&real_rotation, &simple_hitpoint, data, object);
  if (object->type == SPHERE)
    {
      object_normal->x = data->hitpoint.x - object->origin.x;
      object_normal->y = data->hitpoint.y - object->origin.y;
      object_normal->z = data->hitpoint.z - object->origin.z;
    }
  else if (object->type == CYLINDER || object->type == CONE)
    {
      object_normal->x = simple_hitpoint.x - object->origin.x;
      object_normal->y = 0.0;
      object_normal->z = simple_hitpoint.z - object->origin.z;
    }
  else if (object->type == PLANE || object->type == POLYGON)
    {
      object_normal->x = 1.0;
      object_normal->y = 1.0;
      object_normal->z = 1.0;
    }
}

static float	set_attenuation(float light_distance, float final,
				t_object *object, t_lux *lux)
{
  float	constant_attenuation;
  float	linear_attenuation;
  float	quadratic_attenuation;
  float	attenuation;

  constant_attenuation = lux->att.x;
  linear_attenuation = lux->att.y;
  quadratic_attenuation = lux->att.z;
  attenuation =
      1.0 / (constant_attenuation +
	     (linear_attenuation * light_distance) +
	     (quadratic_attenuation * light_distance * light_distance));
  if (object->type == PLANE || object->type == POLYGON)
    return (attenuation);
  if (object->infos.inclinaison.x != 0.0 ||
      object->infos.inclinaison.y != 0.0 || object->infos.inclinaison.z != 0.0)
    return (attenuation);
  return (final * attenuation);
}

static float	compute_lightening(t_object *object, t_data *data,
				   t_lux *lux)
{
  t_position	light_vector;
  t_position	object_normal;
  float		light_distance;
  float		normal_distance;
  float		scalar[2];
  float		final;

  compute_object_normal(object, data, &object_normal);
  light_vector.x = lux->origin.x - data->hitpoint.x;
  light_vector.y = lux->origin.y - data->hitpoint.y;
  light_vector.z = lux->origin.z - data->hitpoint.z;
  light_distance = sqrt((light_vector.x * light_vector.x) +
			(light_vector.y * light_vector.y) +
			(light_vector.z * light_vector.z));
  normal_distance = sqrt((object_normal.x * object_normal.x) +
			 (object_normal.y * object_normal.y) +
			 (object_normal.z * object_normal.z));
  scalar[0] = (object_normal.x * light_vector.x) +
      (object_normal.y * light_vector.y) +
      (object_normal.z * light_vector.z);
  scalar[1] = light_distance * normal_distance;
  final = scalar[0] / scalar[1];
  return (set_attenuation(light_distance, final, object, lux));
}

int		compute_light(t_raytracer *raytracer, t_data *data, t_object *object)
{
  float		coeff;
  float		ratio;
  int		index;
  float		real_coeff;

  index = 0;
  coeff = 0.0;
  while (index < raytracer->nb_lux)
    {
      ratio = compute_lightening(object, data, &raytracer->lux[index]);
      if (ratio < 0.00000)
	ratio = 0.0;
      real_coeff = raytracer->lux[index].intensity * ratio * 0.4;
      coeff += real_coeff;
      index += 1;
    }
  coeff /= (float)index;
  data->light_coeff = coeff;
  return (SUCCESS);
}
