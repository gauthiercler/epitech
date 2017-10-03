/*
** front.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/front.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 11:01:28 2017 Antoine FORET
** Last update Thu Jun 22 11:01:28 2017 Antoine FORET
*/

#include	"list.h"

void		*list_front(t_list *self)
{
  return (self->at(self, 0));
}