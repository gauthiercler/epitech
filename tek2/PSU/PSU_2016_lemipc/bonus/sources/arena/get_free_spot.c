/*
** get_free_spot.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/arena/get_free_spot.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Mar 22 15:42:59 2017 Anas Buyumad
** Last update Wed Mar 22 15:42:59 2017 Anas Buyumad
*/

#include	"lem_ipc.h"

bool		brute_push(char *arena, t_pos *pos)
{
  t_pos		cell;
  int		i;

  i = 0;
  while (i < arena_ss)
  {
    cell.x = xrand() % arena_ss;
    cell.y = xrand() % arena_ss;
    if (arena[CT(cell.x, cell.y)] == FREE_CELL)
    {
      pos->x = cell.x;
      pos->y = cell.y;
      return (true);
    }
    i += 1;
  }
  return (false);
}

bool		get_free_spot(char *arena, t_pos *pos)
{
  t_pos		cell;

  if (brute_push(arena, pos))
    return (true);
  cell.y = 0;
  while (cell.y < arena_ss)
  {
    cell.x = 0;
    while (cell.x < arena_ss)
    {
      if (arena[CT(cell.x, cell.y)] == FREE_CELL)
      {
	pos->x = cell.x;
	pos->y = cell.y;
	return (true);
      }
      cell.x += 1;
    }
    cell.y += 1;
  }
  return (false);
}