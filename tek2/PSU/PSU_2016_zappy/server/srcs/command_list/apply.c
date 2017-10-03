/*
** apply.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/command_list/apply.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 17:23:01 2017 Montagne Valentin
** Last update Thu Jun 29 17:23:01 2017 Montagne Valentin
*/

#include		"command.h"

bool			command_list_apply(t_command_list *self,
					       t_list_action action,
					       void *params)
{
  return (self->list->foreach(self->list, action, params));
}