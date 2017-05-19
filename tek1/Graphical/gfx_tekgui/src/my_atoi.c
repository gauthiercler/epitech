/*
** my_atoi.c for my_atoi in /home/gogo/rendu/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb 15 13:48:03 2016 Gauthier Cler
** Last update Mon Feb 15 22:02:40 2016 Gauthier Cler
*/

#include	"tekgui.h"

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
