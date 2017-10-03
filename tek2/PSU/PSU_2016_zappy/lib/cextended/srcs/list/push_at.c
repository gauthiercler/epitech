/*
** push_at.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/push_at.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 11:16:38 2017 Antoine FORET
** Last update Thu Jun 22 11:16:38 2017 Antoine FORET
*/

#include		<malloc.h>
#include		"list.h"

static t_list_node	*create_node(void *data)
{
  t_list_node		*node;

  node = malloc(sizeof(t_list_node));
  if (node == NULL)
    return (NULL);
  node->data = data;
  node->next = NULL;
  return (node);
}

static void		apply(t_list_node **prev, t_list_node *node,
			 t_list_node *next)
{
  *prev = node;
  node->next = next;
}

static void		insert(t_list_node **prev_link, t_list_node *node,
				  t_list_node *new, unsigned int idx)
{
  if (node == NULL || idx == 0)
    return (apply(prev_link, new, node));
  else
    return (insert(&node->next, node->next, new, idx - 1));
}

bool			list_push_at(t_list *self,
					 void *data,
					 unsigned int idx)
{
  t_list_node		*node;

  node = create_node(data);
  if (node == NULL)
    return (false);
  insert(&self->list, self->list, node, idx);
  return (true);
}