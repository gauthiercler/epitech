/*
** intersection.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/intersection/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue May 10 15:54:03 2016 Buyumad Anas
** Last update Sun May 22 15:47:49 2016 Buyumad Anas
*/

#include	<stdio.h>
#include	"raytracer.h"

static void	assess_position(t_data *data, t_position *object_pos,
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

int		compute_intersection(t_raytracer *raytracer, t_data *data)
{
  int		index;

  index = 0;
  while (index < raytracer->nb_obj)
    {
      assess_position(data, &raytracer->object[index].origin,
		      &raytracer->object[index].infos.inclinaison);
      raytracer->object[index].infos.center_y =
      raytracer->object[index].origin.y;
      raytracer->compute[raytracer->object[index].type]
      (data, &raytracer->object[index].infos, index);
      index += 1;
    }
  return (SUCCESS);
}
