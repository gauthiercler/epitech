/*
** my_put_nbr.c for my_put_nbr in /tmp/PSU_2015_minitalk/server/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sun Feb 21 09:42:23 2016 Gauthier Cler
** Last update Sun Feb 21 09:42:24 2016 Gauthier Cler
*/

#include	"../include/server.h"

void	my_put_nbr(int nb)
{
  int	i;
  int	j;
  int	k;

  i = 1;
  if (nb < 0)
    {
      nb = -(nb);
      my_putchar('-');
    }
  while (nb / i >= 10)
    i = i * 10;
  while (i > 0)
    {
      j = (nb / i);
      k = j % 10;
      my_putchar(k + '0');
      i = i / 10;
    }
}
