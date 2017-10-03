/*
** verif.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/path_finding/solve/verif.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 28 15:57:22 2017 Gauthier Cler
** Last update Tue Mar 28 15:57:24 2017 Gauthier Cler
*/

#include		"solver.h"

int			is_possible(t_node *open, char **map, int direction,
				       t_pos *pos)
{
  int			x;
  int			y;

  x = get_pos_x(open->pos.x, direction);
  y = get_pos_y(open->pos.y, direction);
  if ((x >= ARENA_SS || x < 0) || (y >= ARENA_SS || y < 0))
    return (ERROR);
  if (map[y][x] != POSSIBLE && map[y][x] != WAITING && map[y][x] != EXIT)
    return (ERROR);
  pos->x = x;
  pos->y = y;
  return (SUCCESS);
}
