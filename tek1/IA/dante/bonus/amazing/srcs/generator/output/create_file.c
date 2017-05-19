/*
** create_file.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/output/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Apr 28 23:57:56 2016 Buyumad Anas
** Last update Fri Apr 29 00:07:47 2016 Buyumad Anas
*/

#include	<fcntl.h>
#include	<sys/stat.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	"perfection.h"

int		open_file(char *filename)
{
  int		fd;

  fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC,
	    S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  return (fd);
}

void		write_map(t_map *map, int fd)
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
	    write(fd, "*", 1);
	  else if (map->cells[row][column] == WALL)
	    write(fd, "X", 1);
	  column += 1;
	}
      write(fd, "\n", 1);
      row += 1;
    }
}

void		create_file(t_perfect *perfect)
{
  int		fd;

  if ((fd = open_file(perfect->filename)) == -1)
    exit(format(2, "Couldn't create the file %s.\n", perfect->filename));
  write_map(&perfect->map, fd);
}
