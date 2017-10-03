/*
** at.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/at.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 11:00:01 2017 Antoine FORET
** Last update Thu Jun 22 11:00:01 2017 Antoine FORET
*/

#include	"list.h"

static void	*get_node(t_list_node *node, unsigned int idx)
{
  if (idx == 0 || node == NULL)
    return (node);
  else
    return (get_node(node->next, idx - 1));
}

void		*list_at(t_list *self, unsigned int idx)
{
  t_list_node	*node;

  node = get_node(self->list, idx);
  if (node == NULL)
    return (NULL);
  else
    return (node->data);
}