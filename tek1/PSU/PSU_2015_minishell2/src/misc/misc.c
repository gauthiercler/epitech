/*
** misc.c for misc in /home/gogo/rendu/PSU_2015_minishell2/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Mar 16 08:48:36 2016 Gauthier Cler
** Last update Tue Mar 29 16:31:21 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

void		init_couple(int *a, int *b)
{
  *a = 0;
  *b = 0;
}

void		my_bzero(char *str, int size)
{
  int		count;

  count = 0;
  while (count < size)
    {
      str[count] = '\0';
      count += 1;
    }
}

void		malloc_error()
{
  put_fd(2, "Erreur de malloc\n");
  exit(0);
}
