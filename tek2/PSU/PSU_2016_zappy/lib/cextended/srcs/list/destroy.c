/*
** destroy.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 10:55:47 2017 Antoine FORET
** Last update Thu Jun 22 10:55:47 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"list.h"

static void	delete_list(t_list_node *node)
{
  t_list_node	*next;

  if (node != NULL)
    next = node->next;
  else
    return ;
  free(node);
  return (delete_list(next));
}

void		list_destroy(t_list *self)
{
  delete_list(self->list);
  free(self);
}