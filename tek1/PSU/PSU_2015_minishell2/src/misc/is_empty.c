/*
** is_empty.c for is_empty in /home/gogo/rendu/PSU_2015_minishell2/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Apr 18 13:12:17 2016 Gauthier Cler
** Last update Mon Apr 18 13:31:52 2016 Gauthier Cler
*/

#include		"mysh.h"

int			is_empty(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (SUCCESS);
      i += 1;
    }
  return (ERROR);
}
