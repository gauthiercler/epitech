/*
** util.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/util.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun May 14 15:31:52 2017 Gauthier Cler
** Last update Sun May 14 15:31:52 2017 Gauthier Cler
*/

#include	<memory.h>
#include	<stdlib.h>
#include	<stdio.h>
#include 	<stdbool.h>
#include	<sys/stat.h>
#include	<limits.h>
#include	"misc.h"

char		*string_replace(char *str, char find, char replace)
{
  int		idx;

  if (str == NULL)
    return (NULL);
  idx = 0;
  while (str[idx])
  {
    if (str[idx] == find)
      str[idx] = replace;
    idx += 1;
  }
  return (str);
}

char		*concat(const char *first, const char *second)
{
  char		*result;

  if (first == NULL || second == NULL)
    return (NULL);
  result = malloc(strlen(first) + strlen(second) + 1);
  if (result == NULL)
  {
    perror("malloc");
    return (NULL);
  }
  strcpy(result, first);
  strcat(result, second);
  return (result);
}

bool		is_valid_file(const char *path)
{
  struct stat	file_stat;

  if (path == NULL)
    return (false);
  if (stat(path, &file_stat) < 0
      || !S_ISREG(file_stat.st_mode))
    return (false);
  return (true);
}

bool		is_below_root(const char *base_path, const char *arg)
{
  if (base_path == NULL || arg == NULL)
    return (false);
  if (strlen(arg) < strlen(base_path))
    return (true);
  if (strncmp(base_path, arg, strlen(base_path)) != 0)
    return (true);
  return (false);
}

bool		get_abs_path(char **path)
{
  char		*new_path;

  new_path = malloc(PATH_MAX + 1);
  if (!new_path)
    return (display_error(__func__, "malloc"));
  if (realpath(*path, new_path) == NULL)
  {
    free(new_path);
    return (false);
  }
  free_ptr(path);
  *path = new_path;
  return (true);
}