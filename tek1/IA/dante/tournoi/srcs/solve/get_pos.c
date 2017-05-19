/*
** get_pos.c for get_pos in /home/gogo/rendu/dante/profondeur/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 00:38:33 2016 Gauthier Cler
** Last update Thu Apr 28 00:44:38 2016 Gauthier Cler
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
