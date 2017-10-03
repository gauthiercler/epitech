/*
** empty.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/command_list/empty.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 17:24:34 2017 Montagne Valentin
** Last update Thu Jun 29 17:24:34 2017 Montagne Valentin
*/

#include		"command.h"

static bool		delete_command(t_command *self)
{
  if (self != NULL)
    self->destroy(self);
  return (true);
}

void			command_list_empty(t_command_list *self)
{
  self->apply(self, (t_list_action)(delete_command), NULL);
}