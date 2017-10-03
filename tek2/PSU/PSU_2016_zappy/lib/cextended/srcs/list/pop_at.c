/*
** pop_at.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/pop_at.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 12:32:09 2017 Antoine FORET
** Last update Thu Jun 22 12:32:09 2017 Antoine FORET
*/

#include		<malloc.h>
#include		"list.h"

static bool		remove_node(t_list_node **link_to, t_list_node *node)
{
  if (node == NULL)
    return (false);
  *link_to = node->next;
  free(node);
  return (true);
}

static t_list_node	*get_node(t_list_node *node, unsigned int idx)
{
  if (node == NULL || idx == 0)
    return (node);
  else
    return (get_node(node->next, idx - 1));
}

bool			list_pop_at(t_list *self, unsigned int idx)
{
  t_list_node		*node;

  if (idx == 0)
    return (remove_node(&self->list, self->list));
  node = get_node(self->list, idx - 1);
  if (node == NULL)
    return (false);
  return (remove_node(&node->next, node->next));
}