/*
** load_map.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/bonus/sources/arena/load_map.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Mar 31 18:46:52 2017 Gauthier Cler
** Last update Fri Mar 31 18:46:52 2017 Gauthier Cler
*/

#include	"lem_ipc.h"

bool		is_valid_symbol(char *line)
{
  int		idx;

  line[strlen(line) - 1] = '\0';
  idx = 0;
  while (line[idx])
  {
    if (!is_wall(line[idx]) && line[idx] != FREE_CELL)
      return (false);
    idx += 1;
  }
  return (true);
}

static bool	is_valid_map(FILE *fp)
{
  char		*line;
  size_t	length;
  ssize_t	read;
  int		map_size;
  int		map_y_size;

  length = 0;
  line = NULL;
  map_size = -1;
  map_y_size = 0;
  while ((read = getline(&line, &length, fp)) != -1)
  {
    map_size = (map_size == -1) ? ((int)read - 1) : (map_size);
    if (map_size != read - 1)
      return (custom_error("Invalid map size"));
    if (!is_valid_symbol(line))
      return (custom_error("Invalid Symbol"));
    map_y_size += 1;
  }
  if (map_y_size != map_size)
    return (custom_error("Invalid map size"));
  (line) ? free(line) : 0;
  arena_ss = map_size;
  arena_size = arena_ss * arena_ss;
  return (true);
}

bool		check_map(char *file)
{
  FILE		*fp;

  if (!file)
    return (custom_error("File does not exist"));
  if (!(fp = fopen(file, "r")))
    return (custom_error("Can't open file"));
  if (!is_valid_map(fp))
    return (custom_error("Map not valid"));
  fclose(fp);
  return (true);
}