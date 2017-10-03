/*
** pop_data.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/pop_data.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 12:50:38 2017 Antoine FORET
** Last update Thu Jun 22 12:50:38 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"list.h"

static bool	remove_data(t_list_node **prev,
			    t_list_node *node,
			    void *data,
			    bool status)
{
  t_list_node	*next;
  if (node == NULL)
    return (status);
  next = node->next;
  if (node->data == data)
  {
    *prev = next;
    status = true;
    free(node);
  }
  else
    prev = &node->next;
  return (remove_data(prev, next, data, status));
}

bool		list_pop_data(t_list *self, void *data)
{
  return (remove_data(&self->list, self->list, data, false));
}