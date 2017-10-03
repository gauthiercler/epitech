/*
** search.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/search.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 09:55:56 2017 Antoine FORET
** Last update Wed Jun 28 09:55:56 2017 Antoine FORET
*/

#include	"list.h"

static void	*search(t_list_node *node,
			   t_list_predicate predicate,
			   void *comp)
{
  if (node == NULL)
    return (NULL);
  else if (predicate(node->data, comp))
    return (node->data);
  else
    return (search(node->next, predicate, comp));
}

void		*list_search(t_list *self,
				 t_list_predicate predicate,
				 void *comp)
{
  return (search(self->list, predicate, comp));
}