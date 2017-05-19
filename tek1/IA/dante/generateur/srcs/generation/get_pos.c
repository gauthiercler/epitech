/*
** get_pos.c for get_pos in /home/gogo/rendu/dante/generateur/srcs/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat May 21 17:31:12 2016 Gauthier Cler
** Last update Sat May 21 17:31:48 2016 Gauthier Cler
*/

#include	"perfection.h"

int		get_pos_y(t_list *cell, int direction)
{
  if (direction == NORTH)
    return (cell->cell.pos_y - 1);
  else if (direction == EAST)
    return (cell->cell.pos_y);
  else if (direction == SOUTH)
    return (cell->cell.pos_y + 1);
  return (cell->cell.pos_y);
}

int		get_pos_x(t_list *cell, int direction)
{
  if (direction == NORTH)
    return (cell->cell.pos_x);
  else if (direction == EAST)
    return (cell->cell.pos_x + 1);
  else if (direction == SOUTH)
    return (cell->cell.pos_x);
  return (cell->cell.pos_x - 1);
}
