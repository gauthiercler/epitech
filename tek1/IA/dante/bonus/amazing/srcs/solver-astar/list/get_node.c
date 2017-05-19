/*
** get_node.c for get_node in /home/gogo/rendu/dante/astar/srcs/list/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May  2 23:26:56 2016 Gauthier Cler
** Last update Sun May 22 18:11:21 2016 Gauthier Cler
*/

#include		"astar.h"

t_nodea			*get_node(t_nodea *node, t_nodea new)
{
  t_nodea		*tmp;

  tmp = node;
  while (tmp != NULL)
    {
      if (tmp->pos.x == new.pos.x && tmp->pos.y == new.pos.y)
	return (node);
      tmp = tmp->next;
    }
  return (NULL);
}

t_nodea			*get_lower_node(t_nodea *open)
{
  t_nodea		*tmp;
  t_nodea		*selected;

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
