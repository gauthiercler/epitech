/*
** gen_path.c for gen_path in /home/gogo/rendu/dante/largeur/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr 30 18:40:09 2016 Gauthier Cler
** Last update Thu May  5 16:02:10 2016 Gauthier Cler
*/

#include		"solver.h"

void			find_father_pos(t_node *closed,
					t_pos *father)
{
  static t_node		*tmp = NULL;

  if (tmp == NULL)
  tmp = closed;
  while (father->x != tmp->pos.x || father->y != tmp->pos.y)
    {
      tmp = tmp->next;
      if (tmp == NULL)
	tmp = closed;
    }
  father->x = tmp->father.x;
  father->y = tmp->father.y;
}

t_list			*find_path(t_node *open, t_node *closed, t_node *selected)
{
  t_list		*path;
  t_pos			father;

  path = NULL;
  father.x = selected->father.x;
  father.y = selected->father.y;
  add_to_list(&path, selected->pos.x, selected->pos.y);
  while (father.x != -1 || father.y != -1)
    {
      add_to_list(&path, father.x, father.y);
      find_father_pos(closed, &father);
    }
  clean_node(closed);
  clean_node(open);
  return (path);
}
