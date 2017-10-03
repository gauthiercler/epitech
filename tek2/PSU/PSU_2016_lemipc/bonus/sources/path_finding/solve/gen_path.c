/*
** gen_path.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/path_finding/solve/gen_path.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 28 15:57:02 2017 Gauthier Cler
** Last update Tue Mar 28 15:57:04 2017 Gauthier Cler
*/

#include		"solver.h"

void			find_father_pos(t_node *closed,
					t_pos *father)
{
  t_node		*tmp;

  tmp = closed;
  while (tmp)
    {
      if (father->x == tmp->pos.x && father->y == tmp->pos.y)
      {
	father->x = tmp->father.x;
	father->y = tmp->father.y;
	break ;
      }
      tmp = tmp->next;
    }
}

t_list			*find_path(t_node *open, t_node *closed,
					 t_node *selected)
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
