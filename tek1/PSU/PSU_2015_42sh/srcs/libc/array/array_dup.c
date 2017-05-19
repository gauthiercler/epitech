/*
** array_dup.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/libc/array/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 13:14:59 2016 Vincent Dusautoir
** Last update Sun Jun  5 18:34:29 2016 Gauthier Cler
*/

#include	<string.h>
#include	<stdlib.h>
#include	"libc.h"

/*
** Copy an array into an other memory space
** @params src
** @return array
*/
char		**array_dup(char **src)
{
  char		**array;
  unsigned int	index;

  index = 0;
  if ((array = malloc(sizeof(char *) * (count(src) + 1))) == NULL)
    return (NULL);
  while (src[index] != NULL)
    {
      if ((array[index] = strdup(src[index])) == NULL)
	return (array);
      index++;
    }
  array[index] = NULL;
  return (array);
}
