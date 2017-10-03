/*
** fill.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/command/fill.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 16:59:55 2017 Montagne Valentin
** Last update Thu Jun 29 16:59:55 2017 Montagne Valentin
*/

#include		<stdlib.h>
#include		"command.h"

void			command_fill(t_command *self, t_command_type type,
				 size_t tick, t_player_response resp)
{
  self->type = type;
  self->tick = tick;
  self->response = resp;
}