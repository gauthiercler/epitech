/*
** get_node.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/path_finding/list/get_node.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 28 15:52:27 2017 Gauthier Cler
** Last update Tue Mar 28 15:52:27 2017 Gauthier Cler
*/

#include		"solver.h"

t_node			*get_node(t_node *node, t_node new)
{
  t_node		*tmp;

  tmp = node;
  while (tmp)
    {
      if (tmp->pos.x == new.pos.x && tmp->pos.y == new.pos.y)
	return (tmp);
      tmp = tmp->next;
    }
  return (node);
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
