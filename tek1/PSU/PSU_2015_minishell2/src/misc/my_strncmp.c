/*
** my_strncmp.c for my_strncmp in /home/gogo/rendu/PSU_2015_minishell2/src/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Apr  1 13:29:01 2016 Gauthier Cler
** Last update Sat Apr  2 19:45:01 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

int		my_strncmp(char *str1, char *str2, int count)
{
  int		i;

  i = 0;
  if (str1 == NULL || str2 == NULL)
    return (ERROR);
  while (i < count)
    {
      if (str1[i] != str2[i])
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}
