/*
** gen_path.c for gen_path in /home/gogo/rendu/PSU_2015_minishell2/src/env
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr  2 16:21:32 2016 Gauthier Cler
** Last update Wed Apr  6 23:58:39 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

char		**gen_path(char **ae)
{
  char		**path;
  int		count;

  if ((count = check_env(ae, "PATH=")) == ERROR)
    return (NULL);
  path = separator_to_tab(ae[count] + 5, ':');
  return (path);
}
