/*
** check_env.c for check_env in /home/gogo/rendu/PSU_2015_minishell2/src/env
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Apr  1 13:24:24 2016 Gauthier Cler
** Last update Sat Apr  2 19:46:01 2016 Gauthier Cler
*/

#include	"mysh.h"

int		check_env(char **ae, char *request)
{
  int		i;

  i = 0;
  while (ae[i])
    {
      if (my_strncmp(ae[i], request, my_strlen(request)) == SUCCESS)
	return (i);
      i += 1;
    }
  return (ERROR);
}
