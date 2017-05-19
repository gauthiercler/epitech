/*
** init_threads.c for init_threads in /home/gogo/rendu/gfx_raytracer2/srcs/threading/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed May 11 00:04:49 2016 Gauthier Cler
** Last update Sat May 14 10:36:23 2016 Gauthier Cler
*/

#include	<stdio.h>
#include	"raytracer.h"

void		set_thread_origin(t_data *thread, t_eye *eye)
{
  thread->origin.x = eye->origin.x;
  thread->origin.y = eye->origin.y;
  thread->origin.z = eye->origin.z;
  thread->target.x = 0;
  thread->target.y = 0;
  thread->target.z = 0;
  thread->vector.x = 0;
  thread->vector.y = 0;
  thread->vector.z = 0;
  thread->hitpoint.x = 0;
  thread->hitpoint.y = 0;
  thread->hitpoint.z = 0;
  thread->coeff = 0.0;
  thread->index = 0;
  thread->hit_color.full = BLACK;
}

void		set_thread_area(t_data *threads, int index, int zone)
{
  if (index == 0)
    {
      threads[index].thread_area[0].y = 0;
      threads[index].thread_area[1].y = zone;
    }
  else
    {
      threads[index].thread_area[0].y = threads[index - 1].thread_area[1].y;
      threads[index].thread_area[1].y = zone;
    }
  threads[index].thread_area[0].x = 0;
  threads[index].thread_area[1].x = SCREEN_WIDTH;
}

void		init_threads(t_data *threads, t_eye *eye)
{
  int		index;
  int		zone;
  float		ratio;

  ratio = SCREEN_HEIGHT / NB_THREADS;
  zone = (int)ratio;
  index = 0;
  while (index < NB_THREADS)
    {
      set_thread_origin(&threads[index], eye);
      set_thread_area(threads, index, zone);
      format(1, "Thread %d => start: X = %d Y= %d end: X = %d Y = %d\n", index,
	     threads[index].thread_area[0].x, threads[index].thread_area[0].y,
	     threads[index].thread_area[1].x, threads[index].thread_area[1].y);
      index += 1;
      zone += (int)ratio;
    }
}
