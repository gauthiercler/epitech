/*
** is_numeric.c for is_numeric in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/libc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 14:14:50 2016 Buyumad Anas
** Last update Sun Jun  5 18:30:53 2016 Gauthier Cler
*/

#include	<stddef.h>
#include	"bool.h"

/*
** Checks if the string is a numeric or not
** @params string
** @return bool
*/
t_bool		is_numeric(char *string)
{
  size_t	iterator;

  if (!string)
    return (FALSE);
  (string[0] == '-') ? iterator = 1 : (iterator = 0);
  while (string[iterator])
    {
      if (string[iterator] < '0' || string[iterator] > '9')
	return (FALSE);
      iterator += 1;
    }
  return (TRUE);
}
