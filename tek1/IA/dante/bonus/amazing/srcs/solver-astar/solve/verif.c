/*
** verif.c for verif in /home/gogo/rendu/dante/astar/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May  2 13:42:44 2016 Gauthier Cler
** Last update Sun May 22 16:51:39 2016 Buyumad Anas
*/

#include	"astar.h"

int			is_in_list(t_nodea *list, int x, int y)
{
  t_nodea		*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->pos.x == x && tmp->pos.y == y)
	return (SUCCESS);
      tmp = tmp->next;
    }
  return (ERROR);
}

int			is_possiblea(t_nodea *open, t_mapa *map, int direction,
				       t_posa *pos)
{
  int			x;
  int			y;

  x = get_pos_xa(open->pos.x, direction);
  y = get_pos_ya(open->pos.y, direction);
  if ((x >= map->size_x || x < 0) || (y >= map->size_y || y < 0))
    return (ERROR);
  if (map->array[y][x] == WALL || map->array[y][x] == VISITED)
    return (ERROR);
  pos->x = x;
  pos->y = y;
  return (SUCCESS);
}
