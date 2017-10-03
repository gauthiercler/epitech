/*
** new.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/egg_list/new.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Fri Jun 23 17:07:41 2017 Clement Nancelle
** Last update Fri Jun 23 17:07:41 2017 Clement Nancelle
*/

#include		<stdlib.h>
#include		"egg.h"

static void		egg_list_methods(t_egg_list *self)
{
  self->dump = egg_list_dump;
  self->size = egg_list_size;
  self->first = egg_list_front;
  self->destroy = egg_list_destroy;
  self->pop = egg_list_pop;
  self->push = egg_list_push;
  self->apply = egg_list_apply;
  self->pop_egg = egg_list_pop_egg;
  self->empty = egg_list_empty;
}

static bool		egg_list_init(t_egg_list *self)
{
  self->list = new_list();
  if (self->list == NULL)
    return (false);
  return (true);
}

t_egg_list		*new_egg_list()
{
  t_egg_list		*self;

  self = malloc(sizeof(t_egg_list));
  if (self == NULL)
    return (NULL);
  egg_list_methods(self);
  if (!egg_list_init(self))
  {
    self->destroy(self);
    return (NULL);
  }
  return (self);
}