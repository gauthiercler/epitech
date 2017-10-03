/*
** foreach.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/foreach.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 12:06:35 2017 Antoine FORET
** Last update Wed Jun 28 12:06:35 2017 Antoine FORET
*/

#include	"list.h"

static bool	apply(t_list_node *node, t_list_action action,
			 void *params, bool status)
{
  t_list_node	*next;

  if (node == NULL)
    return (status);
  next = node->next;
  if (!action(node->data, params))
    status = false;
  return (apply(next, action, params, status));
}

bool		list_foreach(t_list *self, t_list_action action,
				 void *params)
{
  return (apply(self->list, action, params, true));
}