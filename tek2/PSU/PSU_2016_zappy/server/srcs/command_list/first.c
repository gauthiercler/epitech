/*
** first.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/command_list/first.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 10:49:10 2017 Antoine FORET
** Last update Fri Jun 30 10:49:10 2017 Antoine FORET
*/

#include	"command.h"

t_command	*command_list_first(t_command_list *self)
{
  if (self->list != NULL)
    return (self->list->front(self->list));
  else
    return (NULL);
}