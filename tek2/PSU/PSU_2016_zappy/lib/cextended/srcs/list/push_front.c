/*
** push_front.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/push_front.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 12:28:18 2017 Antoine FORET
** Last update Thu Jun 22 12:28:18 2017 Antoine FORET
*/

#include	"list.h"

bool		list_push_front(t_list *self, void *data)
{
  return (self->push_at(self, data, 0));
}