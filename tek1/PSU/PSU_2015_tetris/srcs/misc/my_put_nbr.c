/*
** my_put_nbr.c for my_put_nbr in /tmp/PSU_2015_tetris/srcs/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar  1 18:04:24 2016 Gauthier Cler
** Last update Tue Mar  1 18:05:18 2016 Gauthier Cler
*/

#include	"tetris.h"

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
