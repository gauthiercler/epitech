/*
** purge_strings.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/explode/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 23 15:27:26 2016 Buyumad Anas
** Last update Mon May 23 15:27:37 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"ia.h"

static int	purge_length(char *string, int *index)
{
  int		length;
  int		i;

  length = 0;
  i = *index;
  while (string[i] && (string[i] != ' ' && string[i] != '\t'))
    {
      i += 1;
      length += 1;
    }
  return (length);
}

static bool	purge_string(char **strings, int i, char *string, int *index)
{
  int		length;

  if (string[*index] == ' ' || string[*index] == '\t')
    skip_purge(string, index);
  length = purge_length(string, index);
  if ((strings[i] = malloc(sizeof(char) * (length + 1))) == NULL)
    return (false);
  copy_substring(string, strings[i], *index, length);
  *index += length;
  return (true);
}

bool		purge_strings(char **strings, char *string, int count)
{
  int		index;
  int		i;

  i = 0;
  index = 0;
  while (i < count)
    {
      if (!(purge_string(strings, i, string, &index)))
	return (false);
      i += 1;
    }
  strings[i] = NULL;
  return (true);
}
