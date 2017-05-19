/*
** array_row_cpy.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/array/array_row_cpy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 12:48:46 2016 Antoine FORET
** Last update Sun Jun  5 18:34:36 2016 Gauthier Cler
*/

#include	<stdlib.h>

/*
** Copy a row of an array
** @params src
** @return result
*/
char		*array_row_cpy(char *src)
{
  unsigned int	index;
  unsigned int	size;
  char		*result;

  index = 0;
  size = sizeof(*src);
  if ((result = malloc(size)) == NULL)
    return (NULL);
  while (index < size)
    {
      result[index] = src[index];
      index++;
    }
  return (result);
}
