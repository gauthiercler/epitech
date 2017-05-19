/*
** get_pos.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/generator/generation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat May 21 19:15:14 2016 Buyumad Anas
** Last update Sat May 21 19:15:43 2016 Buyumad Anas
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
