/*
** new.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/chrono/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 23 15:54:57 2017 Antoine FORET
** Last update Fri Jun 23 15:54:57 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"chrono.h"

static void	chrono_methods(t_chrono *self)
{
  self->time_elapsed = chrono_time_elapsed;
  self->reset = chrono_reset;
  self->destroy = chrono_destroy;
}

static void	chrono_init(t_chrono *self)
{
  gettimeofday(&self->time, 0);
}

t_chrono	*new_chrono()
{
  t_chrono	*self;

  self = malloc(sizeof(t_chrono));
  if (self == NULL)
    return (NULL);
  chrono_methods(self);
  chrono_init(self);
  return (self);
}