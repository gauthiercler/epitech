/*
** extract.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/strings/extract.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 09:36:00 2016 Antoine FORET
** Last update Sun Jun  5 18:33:51 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<string.h>

/*
** Compute the size of a substring
** @params start of substring, delimiter
** @return size of the current substring
*/
static size_t	size_substring(const char *str, char delimiter)
{
  size_t	size;

  size = 0;
  while (str[size] != '\0' && str[size] != delimiter)
    size++;
  return (size);
}

/*
** Extract a the offset substring from a string
** @params source string, delimiter of substring, index of the wanted substring
** @return success -> allocated substring, failure -> NULL
*/
char		*extract(char *src, char delimiter, unsigned int offset)
{
  unsigned int	index;

  index = 0;
  if (offset > 0)
    {
      while (src[index] != '\0' && src[index] != delimiter)
	index++;
      if (src[index] == '\0')
	return (NULL);
      return (extract(&src[index + 1], delimiter, offset - 1));
  }
  return (strndup(src, size_substring(src, delimiter)));
}
