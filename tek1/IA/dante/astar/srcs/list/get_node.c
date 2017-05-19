/*
** get_node.c for get_node in /home/gogo/rendu/dante/astar/srcs/list/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May  2 23:26:56 2016 Gauthier Cler
** Last update Thu May  5 16:04:42 2016 Gauthier Cler
*/

#include		"solver.h"

t_node		*get_node(t_node *node, t_node new)
{
  static t_node	*tmp = NULL;

  if (tmp == NULL)
    tmp = node;
  while (tmp->pos.x != new.pos.x || tmp->pos.y != new.pos.y)
    {
      tmp = tmp->next;
      if (tmp == NULL)
	tmp = node;
    }
  return (tmp);
}

t_node			*get_lower_node(t_node *open)
{
  t_node		*tmp;
  t_node		*selected;

  tmp = open;
  selected = open;
  while (tmp != NULL)
    {
      if (tmp->f < selected->f)
	  selected = tmp;
      tmp = tmp->next;
    }
  return (selected);
}
