/*
** pop_front.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/pop_front.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 12:38:33 2017 Antoine FORET
** Last update Thu Jun 22 12:38:33 2017 Antoine FORET
*/

#include	"list.h"

bool		list_pop_front(t_list *self)
{
  return (self->pop_at(self, 0));
}