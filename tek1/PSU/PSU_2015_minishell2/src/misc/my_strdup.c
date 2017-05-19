/*
** my_strdup.c for my_strdup in /home/gogo/rendu/PSU_2015_minishell2
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Mar 29 14:56:10 2016 Gauthier Cler
** Last update Sun Apr  3 20:58:37 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

char		*my_strdup(char *str)
{
  char		*res;
  int		i;

  i = 0;
  res = xmalloc(sizeof(char) * my_strlen(str) + 1);
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}
