/*
** base.c for base in /home/cler_g/rendu/my_printf
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 12 09:21:55 2015 Gauthier Cler
** Last update Mon Nov 16 15:53:43 2015 Gauthier Cler
*/

#include <stdlib.h>

int	base_s(long int nb, int base)
{
  long int	i;
  long int	a;
  long int	b;
  unsigned char	*str;

  str = malloc(sizeof(char) * 3);
  a = 1;
  b = 0;
  while (nb >= a)
    a = a * base;
  a = a / base;
  while (a != 0)
    {
      i = nb / a;
      if (i > 9)
	str[b] = i + 7 + '0';
      else
	str[b] = i + '0';
      nb = nb - (a * i);
      a = a / base;
      b++;
    }
  base_s_zero(str);
}

int	base_s_zero(unsigned char *str)
{
  long int	i;

  i = my_strlen(str);
  while (i != 3)
    {
      my_putchar('0');
      i++;
    }
  my_putstr(str);
}

int     the_big_s(unsigned char *str)
{
  long int   i;

  if (str == NULL)
    {
      my_putstr("(null)");
      return (0);
    }
  i = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] >= 127)
        {
          my_putchar('\\');
          base_s(str[i], 8);
        }
      else
        my_putchar(str[i]);
      i++;
    }
}
