/*
** push.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/command_list/push.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 17:20:10 2017 Montagne Valentin
** Last update Thu Jun 29 17:20:10 2017 Montagne Valentin
*/

#include		"command.h"

bool			command_list_push(t_command_list *self,
					      t_command *data)
{
  return (self->list->push_back(self->list, data));
}