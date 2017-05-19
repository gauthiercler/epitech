/*
** my_atof.c for my_atof in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Mar  7 23:23:16 2016 Gauthier Cler
** Last update Thu Mar 10 09:54:35 2016 Gauthier Cler
*/

#include	"raytracer.h"

double		my_atof_calc(const char *str)
{
  int		i;
  int		minus;
  t_atof	a;

  i = -1;
  a.res = 0;
  minus = 1;
  a.decimal = 0;
  while (str[++i] == '-')
    minus *= -1;
  while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
      a.res = a.res * 10 + (str[i] - '0');
      i++;
    }
  if (str[i] == '.')
    i++;
  while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
      a.decimal = a.decimal * 10 + (str[i] - '0');
      i++;
    }
  while (a.decimal > 1)
    a.decimal /= 10;
  return ((a.res + a.decimal) * minus);
}

double		my_atof(const char *str)
{
  if (str == NULL)
    return (0);
  return (my_atof_calc(str));
}
