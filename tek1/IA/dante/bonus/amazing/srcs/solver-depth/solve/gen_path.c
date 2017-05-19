/*
** gen_path.c for gen_path in /home/gogo/rendu/dante/largeur/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr 30 18:40:09 2016 Gauthier Cler
** Last update Tue May  3 20:54:33 2016 Buyumad Anas
*/

#include		"solver.h"

void			find_father_pos(t_pile *visited, int *father_x,
					int *father_y)
{
  t_pile		*tmp;

  tmp = visited;
  while (*father_x != tmp->x || *father_y != tmp->y)
    tmp = tmp->next;
  *father_x = tmp->father_x;
  *father_y = tmp->father_y;
}

t_list_depth			*find_path(t_pile *visited, int father_x, int father_y,
				   t_pos end)
{
  t_list_depth		*path;
  t_pos			pos;

  path = NULL;
  add_to_list(&path, end.x, end.y);
  while (father_x != -1 || father_y != -1)
    {
      pos.x = father_x;
      pos.y = father_y;
      add_to_list(&path, pos.x, pos.y);
      find_father_pos(visited, &father_x, &father_y);
    }
  clean_pile(visited);
  return (path);
}
