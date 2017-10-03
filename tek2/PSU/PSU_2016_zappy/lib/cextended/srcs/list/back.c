/*
** back.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/back.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 11:03:07 2017 Antoine FORET
** Last update Thu Jun 22 11:03:07 2017 Antoine FORET
*/

#include	"list.h"

static void	*get_last_node(t_list_node *node)
{
  if (node == NULL || node->next == NULL)
    return (node);
  else
    return (get_last_node(node->next));
}

void		*list_back(t_list *self)
{
  t_list_node	*node;

  node = get_last_node(self->list);
  if (node == NULL)
    return (NULL);
  else
    return (node->data);
}