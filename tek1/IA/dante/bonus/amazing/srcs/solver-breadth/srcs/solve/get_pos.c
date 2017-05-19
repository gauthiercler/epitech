/*
** get_pos.c for get_pos in /home/gogo/rendu/dante/profondeur/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 00:38:33 2016 Gauthier Cler
** Last update Sat May 21 16:13:09 2016 Buyumad Anas
*/

#include	"breadth.h"

int		get_pos_y_b(int y, int direction)
{
  if (direction == NORTH_BREADTH)
    return (y - 1);
  else if (direction == EAST_BREADTH)
    return (y);
  else if (direction == SOUTH_BREADTH)
    return (y + 1);
  return (y);
}

int		get_pos_x_b(int x, int direction)
{
  if (direction == NORTH_BREADTH)
    return (x);
  else if (direction == EAST_BREADTH)
    return (x + 1);
  else if (direction == SOUTH_BREADTH)
    return (x);
  return (x - 1);
}
