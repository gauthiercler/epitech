/*
** arguments_checking.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/arguments_checking.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon May 08 14:09:26 2017 Gauthier Cler
** Last update Mon May 08 14:09:26 2017 Gauthier Cler
*/

#include 	<stdlib.h>
#include	<ctype.h>
#include	<stdio.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	"macro.h"
#include	"misc.h"

static bool	is_digit(const char *str)
{
  size_t	iterator;

  iterator = 0;
  while (str[iterator])
  {
    if (!isdigit(str[iterator]))
      return (false);
    iterator += 1;
  }
  return (true);
}

static bool	is_valid_path(const char *path)
{
  struct stat	path_stat;

  if (stat(path, &path_stat) < 0
      || !S_ISDIR(path_stat.st_mode))
    return (false);
  return (true);
}

bool		arguments_checking(const char *port, const char *path)
{
  if (!is_digit(port)
    || atoi(port) > 65535)
  {
    fprintf(stderr, "Port must be a number\n");
    return (false);
  }
  if (!is_valid_path(path))
  {
    fprintf(stderr, "%s is not a valid root path\n", path);
    return (false);
  }
  if (chdir(path) == CALL_ERROR)
    return (display_error(__func__, "chdir"));
  return (true);
}