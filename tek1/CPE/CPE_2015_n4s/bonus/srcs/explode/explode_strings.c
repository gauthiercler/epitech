/*
** explode_strings.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/explode/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 23 15:15:31 2016 Buyumad Anas
** Last update Mon May 23 15:31:49 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"ia.h"

static int	explode_length(char *string, int *index, char delimiter)
{
  int		length;
  int		i;

  length = 0;
  i = *index;
  while (string[i] && string[i] != delimiter)
    {
      i += 1;
      length += 1;
    }
  return (length);
}

static bool	explode_string(char **strings, char *string, int index[2],
			       char delimiter)
{
  int		length;

  length = explode_length(string, &index[1], delimiter);
  if ((strings[index[0]] = malloc(sizeof(char) * (length + 1))) == NULL)
    return (false);
  copy_substring(string, strings[index[0]], index[1], length);
  index[1] += length + 1;
  return (true);
}

bool		explode_strings(char **strings, char *string, int count,
				char delimiter)
{
  int		index[2];

  index[0] = 0;
  index[1] = 0;
  while (index[0] < count)
    {
      if (!(explode_string(strings, string, index, delimiter)))
	return (false);
      index[0] += 1;
    }
  strings[index[0]] = NULL;
  return (true);
}
