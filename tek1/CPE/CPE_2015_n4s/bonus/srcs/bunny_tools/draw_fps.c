/*
** draw_fps.c for draw_fps in /home/montag_v/rendu/CPE_2015_n4s/bonus
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Wed May 25 17:49:55 2016 montag_v
** Last update Fri May 27 01:11:27 2016 Gauthier Cler
*/

#include		"ia.h"

t_bunny_response	alive(void *data)
{
  (void)data;
  return (EXIT_ON_SUCCESS);
}

static void		display_tweak(t_raycast *ray)
{
  bunny_blit(&ray->win->buffer, &ray->pix->clipable, 0);
  bunny_display(ray->win);
  bunny_set_loop_main_function(alive);
  bunny_loop(ray->win, 255, NULL);
}

void			smooth_walls(int index, float *rays, int size,
				     t_raycast *data)
{
  int			count;
  int			inc;
  float			value;

  value = rays[index];
  if (index + 1 < NB_RAYS)
    inc = (rays[index + 1] - rays[index]) / size;
  else
    inc = 0;
  count = 0;
  while (count < size)
    {
      disp_line(data, (index * size) + count, abs(value));
      count += 1;
      value += inc;
    }
}

static void		floor_and_sky(t_raycast *data)
{
  int			i;
  unsigned int		*pixel;

  pixel = (unsigned int *)data->pix->pixels;
  i = 0;
  while (i < data->pix->clipable.buffer.width
	 * (data->pix->clipable.buffer.height / 2))
      pixel[i++] = 0xFFE500;
  while (i < data->pix->clipable.buffer.width
	 * data->pix->clipable.buffer.height)
    pixel[i++] = 0xA8A8A3;
}

void			draw_fps(t_raycast *ray, t_data *data)
{
  int			section;
  int			i;

  floor_and_sky(ray);
  i = 0;
  section = ray->pix->clipable.buffer.width / NB_RAYS;
  while (i < NB_RAYS)
    {
      smooth_walls(i, data->rays, section, ray);
      i += 1;
    }
  display_tweak(ray);
}
