/*
** get_pos.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/path_finding/solve/get_pos.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 28 15:57:10 2017 Gauthier Cler
** Last update Tue Mar 28 15:57:10 2017 Gauthier Cler
*/

#include	"solver.h"

int		get_pos_y(int y, int direction)
{
  if (direction == NORTH)
    return (y - 1);
  else if (direction == EAST)
    return (y);
  else if (direction == SOUTH)
    return (y + 1);
  return (y);
}

int		get_pos_x(int x, int direction)
{
  if (direction == NORTH)
    return (x);
  else if (direction == EAST)
    return (x + 1);
  else if (direction == SOUTH)
    return (x);
  return (x - 1);
}
