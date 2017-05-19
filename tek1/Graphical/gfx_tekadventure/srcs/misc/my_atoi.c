/*
** my_atoi.c for my_atoi in /home/gogo/rendu/gfx_tekadventure/srcs/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 13 17:38:12 2016 Gauthier Cler
** Last update Thu Apr 14 10:20:33 2016 valentin montagne
*/

#include	"adventure.h"

int             my_atoi(const char *str)
{
  int           i;
  int           res;

  if (str == NULL)
    return (ERROR);
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
