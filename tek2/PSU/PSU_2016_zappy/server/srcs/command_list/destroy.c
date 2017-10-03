/*
** destroy.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/command_list/destroy.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 17:19:17 2017 Montagne Valentin
** Last update Thu Jun 29 17:19:17 2017 Montagne Valentin
*/

#include		"command.h"

void		command_list_destroy(t_command_list *self)
{
  if (self->list != NULL)
    self->list->destroy(self->list);
  free(self);
}