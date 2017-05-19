/*
** string_from_tab.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/strings/string_from_tab.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 05 19:12:42 2016 Antoine FORET
** Last update Sun Jun 05 19:12:42 2016 Antoine FORET
*/

#include	<malloc.h>
#include	<string.h>
#include	"libc.h"

/*
** Get size of all strings in array
** @params array
** @return size
*/
static unsigned int	get_array_size(char **array)
{
  unsigned int		index;
  unsigned int		size;

  index = 0;
  size = 0;
  while (array[index] != NULL)
    size += strlen(array[index++]);
  return (size);
}

/*
** Concatenate all strings in array into a sigle string
** @params array which contain substrings
** @return concataneted string
*/
char		*string_from_tab(char **array)
{
  unsigned int	size;
  char		*result;
  unsigned int	index;
  unsigned int	index_str;

  size = get_array_size(array);
  index = 0;
  index_str = 0;
  if ((result = malloc(sizeof(char) * (size + count(array) + 1))) == NULL)
    return (NULL);
  while (array[index] != NULL)
  {
    strcpy(&result[index_str], array[index]);
    index_str += strlen(array[index]);
    result[index_str++] = ' ';
    index++;
  }
  if (index_str > 0)
    index_str--;
  result[index_str] = '\0';
  return (result);
}