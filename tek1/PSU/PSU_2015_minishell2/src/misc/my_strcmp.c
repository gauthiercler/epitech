/*
** my_strcmp.c for my_strcmp in /home/gogo/rendu/PSU_2015_minishell2/src/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Apr  1 13:26:03 2016 Gauthier Cler
** Last update Sat Apr  2 16:40:08 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

int		my_strcmp(char *str1, char *str2)
{
  int		i;

  i = 0;
  if (str1 == NULL || str2 == NULL)
    return (ERROR);
  if (my_strlen(str1) != my_strlen(str2))
    return (ERROR);
  while (str1[i])
    {
      if (str1[i] != str2[i])
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}
