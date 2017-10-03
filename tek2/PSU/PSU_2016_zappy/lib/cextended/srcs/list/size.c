/*
** size.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/size.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 10:57:48 2017 Antoine FORET
** Last update Thu Jun 22 10:57:48 2017 Antoine FORET
*/

#include	"list.h"

static size_t	nb_nodes(t_list_node *node, size_t acc)
{
  if (node == NULL)
    return (acc);
  else
    return (nb_nodes(node->next, acc + 1));
}

size_t		list_size(t_list *self)
{
  return (nb_nodes(self->list, 0));
}