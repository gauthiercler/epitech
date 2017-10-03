/*
** push_back.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/push_back.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 12:29:18 2017 Antoine FORET
** Last update Thu Jun 22 12:29:18 2017 Antoine FORET
*/

#include	"list.h"

bool		list_push_back(t_list *self, void *data)
{
  return (self->push_at(self, data, (unsigned int)self->size(self)));
}