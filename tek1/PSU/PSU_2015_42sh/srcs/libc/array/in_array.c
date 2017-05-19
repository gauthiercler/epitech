/*
** in_array.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/array/in_array.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 21:49:27 2016 Antoine FORET
** Last update Sun Jun  5 18:34:52 2016 Gauthier Cler
*/

#include	<string.h>
#include	"bool.h"

/*
** Check if a word is in array
** @params array, needed
** @return success -> TRUE, failure -> FALSE
*/
t_bool		in_array(char **array, char *needed)
{
  unsigned int	index;

  index = 0;
  while (array[index] != NULL)
    {
    if (strcmp(array[index], needed) == 0)
	return (TRUE);
      index++;
    }
  return (FALSE);
}
