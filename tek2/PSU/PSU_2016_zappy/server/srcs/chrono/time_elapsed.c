/*
** time_elapsed.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/chrono/time_elapsed.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 23 16:05:22 2017 Antoine FORET
** Last update Fri Jun 23 16:05:22 2017 Antoine FORET
*/

#include		"chrono.h"

time_t			chrono_time_elapsed(t_chrono *self)
{
  struct timeval	end;
  time_t		diff;

  gettimeofday(&end, 0);
  diff = (end.tv_sec - self->time.tv_sec) * 1000;
  diff += (end.tv_usec - self->time.tv_usec) / 1000.0;
  return (diff);
}