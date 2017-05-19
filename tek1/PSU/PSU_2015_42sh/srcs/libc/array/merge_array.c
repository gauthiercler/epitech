/*
** merge_array.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/array/merge_array.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 05 17:12:16 2016 Antoine FORET
** Last update Sun Jun 05 17:12:16 2016 Antoine FORET
*/

#include	<malloc.h>
#include	"libc.h"

/*
** Merge to array into a single one. The new array is insert in place of the index index
** @params source array, new array, index to insert
** @return merged array
*/
char		**merge_array(char **src, char **new, unsigned int index)
{
  char		**result;
  unsigned int	src_index;
  unsigned int	new_index;

  if ((result = malloc(sizeof(char *) * (count(src) + count(new) + 1))) == NULL)
    return (NULL);
  src_index = 0;
  new_index = 0;
  while (src[src_index] != NULL && src_index < index)
  {
    result[src_index] = src[src_index];
    src_index++;
  }
  while (new[new_index] != NULL)
  {
    result[src_index + new_index] = new[new_index];
    new_index++;
  }
  while (src[src_index] != NULL)
  {
    result[src_index + new_index] = src[src_index];
    src_index++;
  }
  result[src_index] = NULL;
  return (result);
}