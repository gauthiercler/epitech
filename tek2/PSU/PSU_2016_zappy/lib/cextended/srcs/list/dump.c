/*
** dump.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/dump.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 12:57:14 2017 Antoine FORET
** Last update Thu Jun 22 12:57:14 2017 Antoine FORET
*/

#include	"list.h"

static void	dump(t_list_node *node, t_list_dump handler)
{
  if (node == NULL)
    return ;
  handler(node->data);
  return (dump(node->next, handler));
}

void		list_dump(t_list *self, t_list_dump handler)
{
  dump(self->list, handler);
}