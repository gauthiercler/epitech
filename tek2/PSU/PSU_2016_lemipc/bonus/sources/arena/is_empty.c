/*
** is_empty.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/arena/is_empty.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Mar 28 19:59:23 2017 Anas Buyumad
** Last update Tue Mar 28 19:59:23 2017 Anas Buyumad
*/

#include	"lem_ipc.h"

bool		arena_is_empty(char *arena)
{
  t_pos		pos;

  pos.x = 0;
  while (pos.x < arena_ss)
  {
    pos.y = 0;
    while (pos.y < arena_ss)
    {
      if (arena[CT(pos.x, pos.y)] != FREE_CELL &&
	!is_wall(arena[CT(pos.x, pos.y)]))
	return (false);
      pos.y += 1;
    }
    pos.x += 1;
  }
  return (true);
}