/*
** my_put_nbr.c for my_put_nbr in /home/cler_g/rendu/j03
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Wed Sep 30 19:10:02 2015 Gauthier Cler
** Last update Mon Nov 16 20:45:10 2015 Gauthier Cler
*/

int	my_put_nbr_unsigned(unsigned long int nb)
{
  unsigned long int	i;
  unsigned long int	j;

  i = 1;
  if (nb < 0)
    return (0);
  if (nb == 0)
    my_putchar('0');
  if (nb == 1)
    my_putchar('1');
  while (nb > i)
    i = i * 10;
  i = i / 10;
  while (i > 0)
    {
      j = nb / i;
      my_putchar(j + '0');
      nb %= i;
      i = i / 10;
    }
}
