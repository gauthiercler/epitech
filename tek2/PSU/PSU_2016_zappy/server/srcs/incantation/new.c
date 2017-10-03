/*
** new.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/incantation/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 23 17:03:04 2017 Antoine FORET
** Last update Fri Jun 23 17:03:04 2017 Antoine FORET
*/

#include				<malloc.h>
#include				"incantation.h"

static const t_incantation_needs	needs[] =
  {
    {1, 1, 1, 0, 0, 0, 0, 0},
    {2, 2, 1, 1, 1, 0, 0, 0},
    {3, 2, 2, 0, 1, 0, 2, 0},
    {4, 4, 1, 1, 2, 0, 1, 0},
    {5, 4, 1, 2, 1, 3, 0, 0},
    {6, 6, 1, 2, 3, 0, 1, 0},
    {7, 6, 2, 2, 2, 2, 2, 1},
    {0, 50, 50, 50, 50, 50, 50, 50},
  };

static void				incantation_methods(
  t_incantation *self)
{
  self->tick = incantation_tick;
  self->is_ended = incantation_is_ended;
  self->validate = incantation_validate;
  self->destroy = incantation_destroy;
}

static const t_incantation_needs	*get_needs(unsigned int level)
{
  unsigned int				idx;

  idx = 0;
  while (needs[idx].level != level && needs[idx].level != 0)
    idx += 1;
  return (&needs[idx]);
}

static void				incantation_init(
  t_incantation *self, unsigned int time, unsigned int type)
{
  self->time_remaining = time;
  self->needs = get_needs(type);
}

t_incantation				*new_incantation(
  unsigned int time, unsigned int level)
{
  t_incantation				*self;

  self = malloc(sizeof(t_incantation));
  if (self == NULL)
    return (NULL);
  incantation_methods(self);
  incantation_init(self, time, level);
  return (self);
}