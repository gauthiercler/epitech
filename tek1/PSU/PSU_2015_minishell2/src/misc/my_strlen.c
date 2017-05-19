/*
** my_strlen.c for my_strlen in /home/gogo/rendu/PSU_2015_minishell2/src/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Mar 16 09:24:09 2016 Gauthier Cler
** Last update Sun Apr  3 20:55:45 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

int		my_strlen(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
      i += 1;
  return (i);
}
