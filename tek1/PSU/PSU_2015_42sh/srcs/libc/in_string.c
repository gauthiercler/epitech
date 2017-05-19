/*
** in_string.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/in_string.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 14:03:04 2016 Antoine FORET
** Last update Sun Jun  5 18:31:18 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"bool.h"

/*
** seach if a character is in a string
** @params to find character, search string
** @return success -> true, failure -> false
*/
t_bool		in_string(char c, char *str)
{
  unsigned int	index;

  index = 0;
  while (str != NULL && str[index] != '\0')
    {
      if (str[index] == c)
	return (TRUE);
      index++;
    }
  return (FALSE);
}
