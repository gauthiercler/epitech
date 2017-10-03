/*
** new.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/command_list/new.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 17:13:51 2017 Montagne Valentin
** Last update Thu Jun 29 17:13:51 2017 Montagne Valentin
*/

#include		"command.h"

static void	command_list_methods(t_command_list *self)
{
  self->destroy = command_list_destroy;
  self->push = command_list_push;
  self->pop = command_list_pop;
  self->apply = command_list_apply;
  self->empty = command_list_empty;
  self->size = command_list_size;
  self->first = command_list_first;
}

static bool	command_list_init(t_command_list *self)
{
  self->list = new_list();
  return (self->list != NULL);
}

t_command_list		*new_command_list()
{
  t_command_list	*self;

  self = malloc(sizeof(t_command_list));
  if (self == NULL)
    return (NULL);
  command_list_methods(self);
  if (!command_list_init(self))
  {
    self->destroy(self);
    return (NULL);
  }
  return (self);
}