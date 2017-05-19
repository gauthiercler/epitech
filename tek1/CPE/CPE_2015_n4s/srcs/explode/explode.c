/*
** explode.c for minishcap in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_minishell2/srcs/parsing/explode/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Mar 29 21:45:52 2016 Buyumad Anas
** Last update Thu May 26 23:47:51 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"ia.h"

static bool	is_purge_valid(char *string)
{
  int		i;

  i = 0;
  while (string[i])
    {
      if ((string[i] != ' ' && string[i] != '\t') && string[i])
	return (true);
      i += 1;
    }
  return (false);
}

static bool	is_explode_valid(char *string, char delimiter)
{
  int		i;

  i = 0;
  while (string[i])
    {
      if (string[i] != delimiter && string[i])
	return (true);
      i += 1;
    }
  return (false);
}

static char	**explode_purge(char *string)
{
  char		**strings;
  int		count;

  if (!(is_purge_valid(string)) || (count = purge_count(string)) == 0)
    return (NULL);
  if ((strings = malloc(sizeof(char *) * (count + 1))) == NULL)
    return (NULL);
  if (!(purge_strings(strings, string, count)))
    return (NULL);
  return (strings);
}

static char	**explode_delimiter(char *string, char delimiter)
{
  char		**strings;
  int		count;

  if (!(is_explode_valid(string, delimiter)) ||
      (count = explode_count(string, delimiter)) < 4)
    return (NULL);
  if ((strings = malloc(sizeof(char *) * (count + 1))) == NULL)
    return (NULL);
  if (!(explode_strings(strings, string, count, delimiter)))
    return (NULL);
  return (strings);
}

char		**explode(char *string, char delimiter)
{
  if (string == NULL)
    return (NULL);
  if (delimiter == '\0')
    return (explode_purge(string));
  else
    return (explode_delimiter(string, delimiter));
}
