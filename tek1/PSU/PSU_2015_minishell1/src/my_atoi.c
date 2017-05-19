/*
** my_atoi.c for my_atoi in /home/gauthier/rendu/PSU_2015_minishell1/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun Jan 24 23:19:42 2016 Gauthier Cler
** Last update Fri Feb 12 15:22:06 2016 Gauthier Cler
*/

#include	"../include/info.h"

int	my_atoi(const char *str)
{
  int	i;
  int	res;

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
