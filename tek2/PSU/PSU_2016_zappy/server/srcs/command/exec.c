/*
** exec.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/command/exec.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 30 11:47:52 2017 Montagne Valentin
** Last update Fri Jun 30 11:47:52 2017 Montagne Valentin
*/

#include		"command.h"

void			command_exec(t_command *self, t_server *server,
					 t_player *player)
{
  if (self->response != NULL)
    self->response_result = self->response(player, server);
}