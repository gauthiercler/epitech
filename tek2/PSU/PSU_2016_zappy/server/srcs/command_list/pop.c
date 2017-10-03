/*
** pop.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/command_list/pop.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 17:21:23 2017 Montagne Valentin
** Last update Thu Jun 29 17:21:23 2017 Montagne Valentin
*/

#include		"command.h"

bool			command_list_pop(t_command_list *self,
					     t_command *data)
{
  return (self->list->pop_data(self->list, data));
}