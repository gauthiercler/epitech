/*
** start_threads.c for start_threads in /home/gogo/rendu/gfx_raytracer2/srcs/threading/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed May 11 14:42:03 2016 Gauthier Cler
** Last update Sun May 22 19:23:06 2016 Gauthier Cler
*/

#include	<stdio.h>
#include	"raytracer.h"

pthread_mutex_t	mutex;

static void	blur_loop(t_data *thread, t_raytracer *data, int blur_level)
{
  int		i;
  int		j;
  int 		colors[3];

  colors[0] = 0;
  colors[1] = 0;
  colors[2] = 0;
  i = -(blur_level);
  while (i <= blur_level)
    {
      j = -(blur_level);
      while (j <= blur_level)
	{
	  blur_ray_compute(thread, j, i);
	  thread->target.x = thread->thread_area[0].x;
	  if (render_target(data, thread) == ERROR)
	    return ;
	  colors[0] += thread->hit_color.argb[0];
	  colors[1] += thread->hit_color.argb[1];
	  colors[2] += thread->hit_color.argb[2];
	  j += 1;
	}
      i += 1;
    }
  set_final_color(colors, &thread->hit_color, blur_level);
}

static void			*thread_rending(void *data)
{
  int				save;
  t_thread_arg			*arg;

  arg = (t_thread_arg *)data;
  save = arg->thread.thread_area[0].x;
  arg->thread.target.z = 0;
  while (arg->thread.thread_area[0].y < arg->thread.thread_area[1].y)
    {
      arg->thread.thread_area[0].x = save;
      arg->thread.target.y = arg->thread.thread_area[0].y;
      while (arg->thread.thread_area[0].x < arg->thread.thread_area[1].x)
	{
	  arg->thread.target.x = arg->thread.thread_area[0].x;
	  blur_loop(&arg->thread, &arg->data, arg->data.eye.blur_level);
	  render_pixel(&arg->data, &arg->thread);
	  arg->thread.thread_area[0].x += 1;
	}
      while (pthread_mutex_lock(&mutex));
      bunny_blit(&arg->data.win->buffer, &arg->data.pix->clipable, 0);
      bunny_display(arg->data.win);
      pthread_mutex_unlock(&mutex);
      arg->thread.thread_area[0].y += 1;
    }
  return (NULL);
}

static int	wait_threads(t_data *threads)
{
  int		count;

  count = 0;
  while (count < NB_THREADS)
    {
      if (pthread_join(threads[count].thread, NULL) != 0)
	return (ERROR);
      count += 1;
    }
  return (SUCCESS);
}

int		start_threads(t_data *threads, t_raytracer *raytracer)
{
  int		ret;
  int		count;
  t_thread_arg	arg[NB_THREADS];

  count = 0;
  if (pthread_mutex_init(&mutex, NULL)!= 0)
    return (format(2, "Failed to create mutex\n"));
  while (count < NB_THREADS)
    {
      arg[count].data = *(raytracer);
      arg[count].thread = threads[count];
      ret = pthread_create(&threads[count].thread, NULL, thread_rending,
			   (void *)&arg[count]);
      if (ret != 0)
	return (format(2, "Failed to create thread\n"));
      count += 1;
    }
  if (wait_threads(threads) == ERROR)
    return (format(2, "Error while joining threads\n"));
  if (pthread_mutex_destroy(&mutex) != 0)
    return (format(2, "Failed to delete mutex\n"));
  return (SUCCESS);
}
