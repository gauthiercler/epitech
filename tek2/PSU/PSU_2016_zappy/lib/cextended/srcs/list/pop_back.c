/*
** pop_back.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/pop_back.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 12:39:24 2017 Antoine FORET
** Last update Thu Jun 22 12:39:24 2017 Antoine FORET
*/

#include	"list.h"

bool		list_pop_back(t_list *self)
{
  size_t	size;

  size = self->size(self);
  if (size == 0)
    return (false);
  return (self->pop_at(self, (unsigned int)(size - 1)));
}