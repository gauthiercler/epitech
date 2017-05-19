/*
** generation_over.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/generation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 21:40:49 2016 Buyumad Anas
** Last update Wed Apr 27 23:55:20 2016 Buyumad Anas
*/

#include	"perfection.h"

int		generation_over(t_map *map)
{
  int		row;
  int		column;

  row = 0;
  while (row < map->height)
    {
      column = 0;
      while (column < map->width)
	{
	  if (map->cells[row][column] == UNSET)
	    return (ERROR);
	  if (map->cells[row][column] == 8)
	    return (ERROR);
	  column += 1;
	}
      row += 1;
    }
  return (SUCCESS);
}
