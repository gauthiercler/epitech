/*
** my_getnbr.c for my_getnbr in /home/montag_v/rendu/Piscine_exo_b
** 
** Made by valentin montagne
** Login   <montag_v@epitech.net>
** 
** Started on  Thu Oct 15 15:53:12 2015 valentin montagne
** Last update Sat Mar 26 11:40:37 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"asm.h"

int		my_getnbr(char *str)
{
  int		i;
  int		neg;
  int		nb;

  if (str == NULL)
    return (0);
  i = 0;
  neg = 0;
  nb = 0;
  while (str[neg] == '-')
    neg++;
  str += neg;
  while (str[i])
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (0);
      nb = (nb * 10) + (str[i++] - 48);
    }
  if (neg > 0)
    return (nb * -1);
  return (nb);
}
