/*
** time.c for time in /home/cler_g/rendu/PSU_2015_my_ls
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Sat Nov 28 15:29:29 2015 Gauthier Cler
** Last update Sat Nov 28 16:06:59 2015 Gauthier Cler
*/

#include "info.h"

char	*my_time(char *str)
{
  char	*res;
  int	a;

  a = 0;
  res = malloc(sizeof(char) * 19);
  while (a < 12)
    {
      res[a] = str[a + 4];
      a++;
    }
  res[a] = '\0';
  return (res);
}
