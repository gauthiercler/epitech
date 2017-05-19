/*
** check_pipe.c for pipe in /home/gogo/rendu/PSU_2015_minishell2/src/pipe
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr  5 14:02:25 2016 Gauthier Cler
** Last update Sat Apr  9 14:17:08 2016 Gauthier Cler
*/

#include	"mysh.h"

int		check_pipe(char *instruction)
{
  int		i;

  i = 0;
  while (instruction[i])
    {
      if (instruction[i] == '|')
	return (SUCCESS);
      i += 1;
    }
  return (ERROR);
}
