/*
** new.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/command/new.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 16:56:04 2017 Montagne Valentin
** Last update Thu Jun 29 16:56:04 2017 Montagne Valentin
*/

#include		<stdlib.h>
#include		"command.h"

static void		init_methods(t_command *self)
{
  self->fill = command_fill;
  self->add_data = command_add_data;
  self->exec = command_exec;
  self->destroy = destroy_command;
}

t_command		*new_command()
{
  t_command		*cmd;

  cmd = malloc(sizeof(t_command));
  if (cmd == NULL)
    return (NULL);
  init_methods(cmd);
  cmd->type = UNKNOWN;
  cmd->tick = 0;
  cmd->has_data = false;
  cmd->params = NULL;
  cmd->response_result = false;
  cmd->response = NULL;
  return (cmd);
}