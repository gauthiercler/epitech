/*
** display.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/output/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Apr 28 23:57:23 2016 Buyumad Anas
** Last update Thu Apr 28 23:57:36 2016 Buyumad Anas
*/

#include	"perfection.h"

void		disp_map(t_map *map)
{
  int		i;
  int		j;

  i = 0;
  while (i < map->height)
    {
      j = 0;
      while (j < map->width)
	{
	  if (map->cells[i][j] == WALL)
	    format(1, "%s%d %s", KRED, map->cells[i][j], KRESET);
	  else if (map->cells[i][j] == 8)
	    format(1, "%s%d %s", KYEL, map->cells[i][j], KRESET);
	  else if (map->cells[i][j] == PATH)
	    format(1, "%s%d %s", KGRN, map->cells[i][j], KRESET);
	  else
	    format(1, "%d ", map->cells[i][j]);
	  j += 1;
	}
      format(1, "\n");
      i += 1;
    }
}
