/*
** imperfection.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/imperfection/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 00:32:49 2016 Buyumad Anas
** Last update Fri Apr 29 00:45:26 2016 Buyumad Anas
*/

#include	"perfection.h"

int		breach_possible(t_map *map, int pos_x, int pos_y)
{
  t_list	wall;
  int		errors;

  errors = 0;
  wall.cell.pos_x = pos_x;
  wall.cell.pos_y = pos_y;
  (check_imperfect_walls(map, &wall, NORTH) == ERROR) ? errors += 1 : 0;
  (check_imperfect_walls(map, &wall, EAST) == ERROR) ? errors += 1 : 0;
  (check_imperfect_walls(map, &wall, SOUTH) == ERROR) ? errors += 1 : 0;
  (check_imperfect_walls(map, &wall, WEST) == ERROR) ? errors += 1 : 0;
  if (errors == 4)
    return (ERROR);
  if ((rand() % 4) == 2)
    return (SUCCESS);
  return (ERROR);
}

void		breacher(t_map *map, int pos_x, int pos_y, int *breach)
{
  if (breach_possible(map, pos_x, pos_y) == SUCCESS)
    {
      map->cells[pos_x][pos_y] = PATH;
      *breach += 1;
    }
}

void		imperfection(t_perfect *perfect)
{
  int		row;
  int		column;
  int		broke;
  int		breach;

  row = 0;
  broke = 0;
  breach = (perfect->map.height / 2) + (perfect->map.width / 2);
  while (row < perfect->map.height && broke < breach)
    {
      column = 0;
      while (column < perfect->map.width && broke < breach)
	{
	  if (perfect->map.cells[row][column] == WALL)
	    breacher(&perfect->map, row, column, &breach);
	  column += 1;
	}
      row += 1;
    }
}
