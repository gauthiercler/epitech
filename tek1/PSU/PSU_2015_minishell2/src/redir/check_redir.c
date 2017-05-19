/*
** check_redir.c for check_redir in /home/gogo/rendu/PSU_2015_minishell2/src/redir
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Apr  8 23:33:20 2016 Gauthier Cler
** Last update Tue Apr 19 00:10:05 2016 Gauthier Cler
*/

#include	"mysh.h"

int		check_redir(char *instruction)
{
  int		i;

  i = 0;
  while (instruction[i])
    {
      if (instruction[i] == '>' || instruction[i] == '<')
	return (SUCCESS);
      i += 1;
    }
  return (ERROR);
}
