/*
** my_exit.c for my_exit in /home/gogo/rendu/PSU_2015_minishell2/src/cmd
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr  2 18:18:51 2016 Gauthier Cler
** Last update Sat Apr  2 18:30:09 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

void		my_exit(char **cmd)
{
  if (cmd[1] == NULL)
    exit(0);
  else
    {
      if (cmd[2] != NULL || (is_num(cmd[1]) == ERROR))
	format(2, "exit: Expression Syntax.\n");
      else
	exit(my_atoi(cmd[1]));
    }
}
