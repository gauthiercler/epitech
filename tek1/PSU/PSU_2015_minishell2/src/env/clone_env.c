/*
** clone_env.c for clone_env in /home/gogo/rendu/PSU_2015_minishell2/src/env
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr  2 16:54:43 2016 Gauthier Cler
** Last update Sun Apr  3 20:33:24 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

char		**clone_env(char **ae)
{
  int		i;
  char		**res;

  if (ae == NULL)
    return (NULL);
  i = 0;
  while (ae[i])
    i += 1;
  res = xmalloc(sizeof(char *) * (i + 1));
  i = 0;
  while (ae[i])
    {
      res[i] = my_strdup(ae[i]);
      i += 1;
    }
  res[i] = NULL;
  return (res);
}
