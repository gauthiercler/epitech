/*
** strcat.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/strings/strcat.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 09:49:37 2016 Antoine FORET
** Last update Sun Jun  5 18:33:59 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<string.h>

/*
** Concatenate two strings separated by a char defined as parameter
** @params start string, end string, delimiter
*/
char		*strcat_ret_only(const char *start, const char *end,
				     char separator)
{
  char		*concat;
  unsigned int	index_start;
  unsigned int	index_end;

  if ((concat = malloc(sizeof(char) * (strlen(start) + strlen(end) + 2)))
      == NULL)
    return (NULL);
  index_start = 0;
  index_end = 0;
  while (start[index_start] != '\0')
  {
      concat[index_start] = start[index_start];
      index_start++;
    }
  if (separator != '\0')
    concat[index_start++] = separator;
  while (end[index_end] != '\0')
    {
      concat[index_end + index_start] = end[index_end];
      index_end++;
    }
  concat[index_end + index_start] = '\0';
  return (concat);
}
