/*
** my_atoi.c for my_atoi in /home/gogo/rendu/PSU_2015_minishell2/src/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr  2 18:23:00 2016 Gauthier Cler
** Last update Sat Apr  2 18:23:02 2016 Gauthier Cler
*/

#include	"mysh.h"

int             my_atoi(char *str)
{
  int           i;
  int           res;

  if (str[0] == '-')
    return (-my_atoi(str + 1));
  i = 0;
  res = 0;
  while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
      res = res * 10 + str[i] - '0';
      i++;
    }
  return (res);
}
