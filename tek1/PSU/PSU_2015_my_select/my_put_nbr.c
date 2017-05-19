/*
** my_put_nbr.c for my_put_nbre in /home/gauthier/rendu/PSU_2015_my_select
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Dec  8 17:49:52 2015 Gauthier Cler
** Last update Tue Dec  8 17:49:54 2015 Gauthier Cler
*/

int	my_put_nbr(long int nb)
{
  long int	i;
  long int	j;
  long int	k;

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
