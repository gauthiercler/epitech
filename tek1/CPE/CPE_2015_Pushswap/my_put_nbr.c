/*
** my_put_nbr.c for my_put_nbr in /home/cler_g/rendu/j03
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Wed Sep 30 19:10:02 2015 Gauthier Cler
** Last update Sat Nov 21 18:30:12 2015 Gauthier Cler
*/

int	my_put_nbr(int nb)
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
