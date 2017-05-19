/*
** is_num.c for is_num in /home/gogo/rendu/PSU_2015_minishell2/src/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr  2 18:23:15 2016 Gauthier Cler
** Last update Sat Apr  2 18:30:29 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

int		is_num(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (ERROR);
  if (str[0] == '-')
    i += 1;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}
