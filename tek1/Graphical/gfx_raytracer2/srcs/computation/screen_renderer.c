/*
** screen_renderer.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri May 20 16:40:13 2016 Buyumad Anas
** Last update Sun May 22 15:44:43 2016 Buyumad Anas
*/

#include	<stdio.h>
#include	"raytracer.h"

static void	set_hitcolor(t_raytracer *raytracer, t_data *data)
{
  if (data->index >= 0)
    {
      if (raytracer->object[data->index].type == POLYGON)
	{
	  data->hit_color.full =
	    raytracer->mtl
	    [raytracer->object[data->index].infos.triangle
	     [data->polygon_index].index_color].color.full;
	}
      else
	data->hit_color.full = raytracer->object[data->index].infos.color.full;
      if (raytracer->object[data->index].infos.texture != NULL)
	texture_surface(data, &raytracer->object[data->index],
			raytracer->texture, raytracer);
      if (raytracer->object[data->index].infos.cylinder_top)
	{
	  data->hit_color.argb[0] *= 0.90;
	  data->hit_color.argb[1] *= 0.90;
	  data->hit_color.argb[2] *= 0.90;
	}
    }
  else
    data->hit_color.full = BLACK;
  data->hit_color.argb[3] = 255;
}

void		save(t_position *save_origin, t_position *save_vector, t_data *data)
{
  save_origin->x = data->origin.x;
  save_origin->y = data->origin.y;
  save_origin->z = data->origin.z;
  save_vector->x = data->vector.x;
  save_vector->y = data->vector.y;
  save_vector->z = data->vector.z;
}

void		restore(t_position *save_origin, t_position *save_vector, t_data *data)
{
  data->origin.x = save_origin->x;
  data->origin.y = save_origin->y;
  data->origin.z = save_origin->z;
  data->vector.x = save_vector->x;
  data->vector.y = save_vector->y;
  data->vector.z = save_vector->z;
}

int		render_target(t_raytracer *raytracer, t_data *data)
{
  t_position	save_origin;
  t_position	save_vector;

  data->coeff = -1.0;
  data->index = -1;
  compute_intersection(raytracer, data);
  set_hitcolor(raytracer, data);
  if (data->index >= 0)
    {
      save(&save_origin, &save_vector, data);
      configure_hitpoint(data);
      if (raytracer->nb_lux > 0)
	{
	compute_light(raytracer, data, &raytracer->object[data->index]);
	compute_shadow(raytracer, data);
	compute_color(data);
	}
      restore(&save_origin, &save_vector, data);
    }
  return (SUCCESS);
}

int		render_screen(t_raytracer *raytracer)
{
  t_data	threads[NB_THREADS];

  init_threads(threads, &raytracer->eye);
  if (start_threads(threads, raytracer) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
