/*
** strpos.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Extended/C/srcs/strpos.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 10 08:56:10 2017 Antoine FORET
** Last update Wed May 10 08:56:10 2017 Antoine FORET
*/

#include	<memory.h>
#include	"string_extended.h"

const char	*strstr_binary(const char *haystack,
				 unsigned int haystack_size,
				 const char *needle,
				 unsigned int needle_size)
{
  const char	*start;
  unsigned int	haystack_idx;
  unsigned int	needle_idx;

  haystack_idx = 0;
  needle_idx = 0;
  start = NULL;
  while (haystack_idx < haystack_size && needle_idx < needle_size)
  {
    if (haystack[haystack_idx] == needle[needle_idx])
    {
      if (needle_idx == 0)
	start = &haystack[haystack_idx];
      needle_idx += 1;
    }
    else
      needle_idx = 0;
    haystack_idx += 1;
  }
  if (needle_idx >= needle_size)
    return (start);
  else
    return (NULL);
}

ssize_t		strpos(const char *haystack, const char *needle)
{
  char *substring;

  if (haystack == NULL || needle == NULL)
    return (-1);
  substring = strstr(haystack, needle);
  if (substring != NULL)
    return (substring - haystack);
  return (-1);
}

ssize_t		strpos_binary(const char *haystack,
				     unsigned int haystack_size,
				     const char *needle,
				     unsigned int needle_size)
{
  const char	*substring;

  if (haystack == NULL || needle == NULL)
    return (-1);
  substring = strstr_binary(haystack, haystack_size, needle, needle_size);
  if (substring != NULL)
    return (substring - haystack);
  return (-1);
}