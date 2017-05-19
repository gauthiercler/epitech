/*
** my_atoi.c for ia in /home/gogo/rendu/CPE_2015_n4s/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr 26 22:05:33 2016 Gauthier Cler
** Last update Tue Apr 26 22:05:39 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"ia.h"

int             my_atoi(char *str)
{
  int           i;
  int           res;

  if (str == NULL)
    return (ERROR);
  if (str[0] == '-')
    return (-my_atoi(str + 1));
  i = 0;
  res = 0;
  while (str[i])
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (ERROR);
      res = res * 10 + str[i] - '0';
      i++;
    }
  return (res);
}
