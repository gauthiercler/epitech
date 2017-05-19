/*
** get_pos.c for get_pos in /home/gogo/rendu/dante/profondeur/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 00:38:33 2016 Gauthier Cler
** Last update Sun May 22 16:50:51 2016 Buyumad Anas
*/

#include	"astar.h"

int		get_pos_ya(int y, int direction)
{
  if (direction == NORTH_A)
    return (y - 1);
  else if (direction == EAST_A)
    return (y);
  else if (direction == SOUTH_A)
    return (y + 1);
  return (y);
}

int		get_pos_xa(int x, int direction)
{
  if (direction == NORTH_A)
    return (x);
  else if (direction == EAST_A)
    return (x + 1);
  else if (direction == SOUTH_A)
    return (x);
  return (x - 1);
}
