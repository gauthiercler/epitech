/*
** my_atof.c for my_atof in /home/gauthier/rendu/gfx_wolf3d/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Jan  2 23:14:29 2016 Gauthier Cler
** Last update Sun Jan  3 00:08:36 2016 Gauthier Cler
*/

#include	"wolf.h"

float		my_atof(const char *str)
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
