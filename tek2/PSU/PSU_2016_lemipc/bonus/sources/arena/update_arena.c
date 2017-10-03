/*
** copy_arena.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/arena/copy_arena.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 28 10:52:19 2017 Gauthier Cler
** Last update Tue Mar 28 10:52:19 2017 Gauthier Cler
*/

#include	"lem_ipc.h"

void		update_arena(char *source, char **dest)
{
  int		x;
  int		y;

  y = 0;
  while (y < arena_ss)
  {
    x = 0;
    while (x < arena_ss)
    {
      dest[y][x] = source[CT(x, y)];
      x += 1;
    }
    dest[y][x] = '\0';
    y += 1;
  }
  dest[y] = NULL;
}