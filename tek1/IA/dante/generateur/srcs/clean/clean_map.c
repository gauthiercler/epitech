/*
** clean_map.c for clean_map in /home/gogo/rendu/dante/generation/perfection/srcs/clean/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr 26 17:45:00 2016 Gauthier Cler
** Last update Tue Apr 26 17:46:29 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		"perfection.h"

void			clean_map(t_map *map)
{
  int			i;

  i = 0;
  while (i < map->width)
    {
      free(map->cells[i]);
      i += 1;
    }
  free(map->cells);
}
