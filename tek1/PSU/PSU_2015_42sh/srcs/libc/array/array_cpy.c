/*
** array_cpy.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/array/array_cpy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 12:45:26 2016 Antoine FORET
** Last update Sun Jun  5 18:34:24 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"libc.h"

/*
** Copy an array in other array
** @params src
** @return array
*/
char		**array_cpy(char **src)
{
  char		**array;
  unsigned int	index;

  index = 0;
  if ((array = malloc(sizeof(char *) * (count(src) + 1))) == NULL)
    return (NULL);
  while (src[index] != NULL)
    {
      array[index] = src[index];
      index++;
    }
  array[index] = NULL;
  return (array);
}
