/*
** create_file.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/output/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Apr 28 23:57:56 2016 Buyumad Anas
** Last update Sun May 22 20:09:48 2016 Gauthier Cler
*/

#include	<fcntl.h>
#include	<sys/stat.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	"perfection.h"

void		write_map(t_map *map)
{
  int		row;
  int		column;

  row = 0;
  while (row < map->height)
    {
      column = 0;
      while (column < map->width)
	{
	  if (map->cells[row][column] == PATH)
	    write(1, "*", 1);
	  else if (map->cells[row][column] == WALL)
	    write(1, "X", 1);
	  column += 1;
	}
      if (row + 1 < map->width)
	write(1, "\n", 1);
      row += 1;
    }
}
