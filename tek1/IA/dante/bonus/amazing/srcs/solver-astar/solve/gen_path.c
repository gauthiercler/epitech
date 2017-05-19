/*
** gen_path.c for gen_path in /home/gogo/rendu/dante/largeur/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr 30 18:40:09 2016 Gauthier Cler
** Last update Sun May 22 18:05:49 2016 Gauthier Cler
*/

#include		"astar.h"

void			find_father_posa(t_nodea *closed, t_posa *father)
{
  t_nodea		*tmp;

  tmp = closed;
  while (tmp != NULL)
    {
      if (father->x == tmp->pos.x && father->y == tmp->pos.y)
	{
	  father->x = tmp->father.x;
	  father->y = tmp->father.y;
	  return ;
	}
      tmp = tmp->next;
    }
}

t_lista			*find_patha(t_nodea *open, t_nodea *closed,
				    t_nodea *selected)
{
  t_lista		*path;
  t_posa		father;

  path = NULL;
  father.x = selected->father.x;
  father.y = selected->father.y;
  add_to_lista(&path, selected->pos.x, selected->pos.y);
  while (father.x != -1 || father.y != -1)
    {
      add_to_lista(&path, father.x, father.y);
      find_father_posa(closed, &father);
    }
  clean_node(closed);
  clean_node(open);
  return (path);
}
