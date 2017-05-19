/*
** load_map.c for loading in /home/gogo/rendu/dante/profondeur/srcs/loading.c/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 22:42:38 2016 Gauthier Cler
** Last update Thu Apr 28 23:11:11 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"solver.h"

int		check_valid(char *line)
{
  int		i;

  i = 0;
  while (line[i])
    {
      if (line[i] != POSSIBLE && line[i] != WALL)
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}

int		count_map_size(int fd, int *size_x, int *size_y)
{
  char		*buffer;

  *size_x = 0;
  if ((buffer = get_next_line(fd)) == NULL)
    return (format(2, "Error while reading.\n"));
  if ((*size_x = str_len(buffer)) == 0)
    return (format(2, "Invalid map size.\n"));
  if (check_valid(buffer) == ERROR)
    return (format(2, "Invalid map symbols.\n"));
  free(buffer);
  while ((buffer = get_next_line(fd)) != NULL)
    {
      if (str_len(buffer) != *size_x)
	return (format(2, "Invalid map size.\n"));
      if (check_valid(buffer) == ERROR)
	return (format(2, "Invalid map symbols.\n"));
      free(buffer);
      *size_y += 1;
    }
  return (SUCCESS);
}

char		**create_map(int fd, int size_y)
{
  char		**map;
  int		i;

  i = 0;
  map = xmalloc(sizeof(char *) * (size_y + 1));
  while (i < size_y)
    {
      if ((map[i] = get_next_line(fd)) == NULL)
	return (p_error("Error while reading.\n"));
      i += 1;
    }
  map[i] = NULL;
  return (map);
}

char		**load_map(char *filename, int *size_x, int *size_y)
{
  char		**map;
  int		fd;

  *size_y = 1;
  if ((fd = open(filename, O_RDONLY)) == -1)
    return (p_error("Error while opening map.\n"));
  if (count_map_size(fd, size_x, size_y) == ERROR)
    return (NULL);
  if (lseek(fd, 0, SEEK_SET) == -1)
    return (p_error("Error lseeking.\n"));
  map = create_map(fd, *size_y);
  if (close(fd) == -1)
    return (p_error("Error while closing map.\n"));
  return (map);
}
