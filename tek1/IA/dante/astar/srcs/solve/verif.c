/*
** verif.c for verif in /home/gogo/rendu/dante/astar/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May  2 13:42:44 2016 Gauthier Cler
** Last update Mon May  2 22:47:42 2016 Gauthier Cler
*/

#include	"solver.h"

int			is_in_list(t_node *list, int x, int y)
{
  t_node		*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->pos.x == x && tmp->pos.y == y)
	return (SUCCESS);
      tmp = tmp->next;
    }
  return (ERROR);
}

int			is_possible(t_node *open, t_map *map, int direction,
				       t_pos *pos)
{
  int			x;
  int			y;

  x = get_pos_x(open->pos.x, direction);
  y = get_pos_y(open->pos.y, direction);
  if ((x >= map->size_x || x < 0) || (y >= map->size_y || y < 0))
    return (ERROR);
  if (map->array[y][x] == WALL || map->array[y][x] == VISITED)
    return (ERROR);
  pos->x = x;
  pos->y = y;
  return (SUCCESS);
}
