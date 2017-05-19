/*
** my_atoi.c for my_atoi in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Mar  7 23:22:58 2016 Gauthier Cler
** Last update Thu Mar 10 09:55:46 2016 Gauthier Cler
*/

#include	"raytracer.h"

int	my_atoi(const char *str)
{
  int	i;
  int	res;

  if (str == NULL)
    return (0);
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
