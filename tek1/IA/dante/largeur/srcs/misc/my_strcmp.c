/*
** my_strcmp.c for my_strcmp in /home/gogo/rendu/dante/profondeur
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Thu Apr 28 23:03:01 2016 Gauthier Cler
** Last update Thu Apr 28 23:03:23 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"solver.h"

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (ERROR);
  if (str_len(s1) != str_len(s2))
    return (ERROR);
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}
