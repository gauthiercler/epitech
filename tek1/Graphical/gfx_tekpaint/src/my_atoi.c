/*
** my_atoi.c for my_atoi in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan  5 16:33:47 2016 Gauthier Cler
** Last update Tue Jan 26 21:27:49 2016 Gauthier Cler
*/

#include	"tekpaint.h"

int		my_atoi(unsigned char	*str)
{
  int		i;
  int		res;

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
