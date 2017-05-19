/*
** my_atof.c for my_atof in /home/gogo/rendu/gfx_raytracer2/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May  9 15:25:06 2016 Gauthier Cler
** Last update Sun May 22 10:31:51 2016 montag_v
*/

#include	"raytracer.h"

float		my_atof(const char *str)
{
  int           i;
  int           minus;
  float		res;
  float		decimal;

  i = -1;
  res = 0;
  minus = 1;
  decimal = 0;
  if (str == NULL)
    return (0);
  while (str[++i] == '-')
    minus *= -1;
  while (str[i] >= '0' && str[i] <= '9' && str[i])
    res = res * 10 + (str[i++] - '0');
  (str[i] == '.') ? i++ : 0;
  while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
      decimal = decimal * 10 + (str[i] - '0');
      i++;
    }
  while (decimal > 1)
    decimal /= 10;
  return ((res + decimal) * minus);
}
