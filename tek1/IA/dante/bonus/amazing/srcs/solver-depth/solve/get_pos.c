/*
** get_pos.c for get_pos in /home/gogo/rendu/dante/profondeur/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 00:38:33 2016 Gauthier Cler
** Last update Tue May  3 20:56:43 2016 Buyumad Anas
*/

#include	"solver.h"

int		get_pos_y_depth(int y, int direction)
{
  if (direction == NORTH_DEPTH)
    return (y - 1);
  else if (direction == EAST_DEPTH)
    return (y);
  else if (direction == SOUTH_DEPTH)
    return (y + 1);
  return (y);
}

int		get_pos_x_depth(int x, int direction)
{
  if (direction == NORTH_DEPTH)
    return (x);
  else if (direction == EAST_DEPTH)
    return (x + 1);
  else if (direction == SOUTH_DEPTH)
    return (x);
  return (x - 1);
}
