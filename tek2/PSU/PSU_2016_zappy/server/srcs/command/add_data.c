/*
** add_data.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/command/add_data.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 30 11:13:20 2017 Montagne Valentin
** Last update Fri Jun 30 11:13:20 2017 Montagne Valentin
*/

#include		"command.h"

void			command_add_data(t_command *self, void *data)
{
  if (data != NULL)
  {
    self->has_data = true;
    self->params = data;
  }
}