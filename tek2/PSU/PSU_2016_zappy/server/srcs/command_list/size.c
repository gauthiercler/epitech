/*
** size.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/command_list/size.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 18:08:04 2017 Montagne Valentin
** Last update Thu Jun 29 18:08:04 2017 Montagne Valentin
*/

#include		"command.h"

size_t			command_list_size(t_command_list *self)
{
  return (self->list->size(self->list));
}