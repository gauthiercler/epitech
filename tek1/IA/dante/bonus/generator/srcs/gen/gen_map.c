/*
** gen_map.c for gen_map in /home/gogo/rendu/dante/generation/perfection/gen/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr 26 17:13:06 2016 Gauthier Cler
** Last update Fri Apr 29 00:16:14 2016 Buyumad Anas
*/

#include	"perfection.h"

void		init_cell(int *cell, int size)
{
  int		i;

  i = 0;
  while (i < size)
    {
      cell[i] = UNSET;
      i += 1;
    }
}

void		gen_map(t_map *map)
{
  int		i;

  i = 0;
  map->cells = xmalloc(sizeof(int *) * map->height);
  while (i < map->height)
    {
      map->cells[i] = xmalloc(sizeof(int) * map->width);
      init_cell(map->cells[i], map->width);
      i += 1;
    }
}
