/*
** gen_path.c for gen_path in /home/gogo/rendu/dante/largeur/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr 30 18:40:09 2016 Gauthier Cler
** Last update Sun May 22 23:13:39 2016 Gauthier Cler
*/

#include		"breadth.h"

void			find_father_posb(t_pileb *visited, int *father_x,
					int *father_y)
{
  t_pileb		*tmp;

  tmp = visited;
  while (tmp != NULL)
    {
      if (*father_x == tmp->x && *father_y == tmp->y)
	{
	  *father_x = tmp->father_x;
	  *father_y = tmp->father_y;
	  return ;
	}
      tmp = tmp->next;
    }
}

t_listb			*find_pathb(t_pileb *visited, int father_x, int father_y,
				   t_posb end)
{
  t_listb		*path;
  t_posb		pos;

  path = NULL;
  add_to_listb(&path, end.x, end.y);
  while (father_x != -1 || father_y != -1)
    {
      pos.x = father_x;
      pos.y = father_y;
      add_to_listb(&path, pos.x, pos.y);
      find_father_posb(visited, &father_x, &father_y);
    }
  return (path);
}
