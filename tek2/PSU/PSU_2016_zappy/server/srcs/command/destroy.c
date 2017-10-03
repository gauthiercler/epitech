/*
** destroy.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/command/destroy.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 16:56:58 2017 Montagne Valentin
** Last update Thu Jun 29 16:56:58 2017 Montagne Valentin
*/

#include		<stdlib.h>
#include		"command.h"

void			destroy_command(t_command *self)
{
  if (self->has_data && self->params != NULL)
    free(self->params);
  free(self);
}