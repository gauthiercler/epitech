/*
** my_printf.c for my_printf in /home/cler_g/rendu/my_printf
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov  5 16:39:12 2015 Gauthier Cler
** Last update Mon Nov 16 23:24:34 2015 Gauthier Cler
*/

#include <stdarg.h>
#include <stdlib.h>

int	my_printf(char *str, ...)
{
  int	i;
  int	j;
  va_list	va;

  if (str == NULL)
    return (0);
  va_start(va, str);
  i = 0;
  while (str[i])
    {
      if (str[i] == '%')
	{
	  i++;
	  if (str[i] == 's')
	    null(va);
	  else if (str[i] == 'd' || str[i] == 'i')
	    my_put_nbr(va_arg(va, long int));
	  else
	    i = conditions(va, i, str);
	}
      else
	my_putchar(str[i]);
      i++;
    }
  va_end(va);
}

int	conditions(va_list va, int i, char *str)
{
  if (str[i] == 'u')
    my_put_nbr_unsigned(va_arg(va, unsigned long int));
  else  if (str[i] == 'c')
    my_putchar(va_arg(va, int));
  else if (str[i] == 'x')
    base_mini(va_arg(va, int), 16);
  else if (str[i] == 'X')
    base(va_arg(va, int), 16);
  else if (str[i] == 'b')
    base(va_arg(va, int), 2);
  else if (str[i] == 'p')
    adresse(va_arg(va, long int));
  else if (str[i] == 'o')
    base(va_arg(va, int), 8);
  else if (str[i] == 'S')
    the_big_s(va_arg(va, unsigned char*));
  else if (str[i] == '#')
    i = sharp(i, va_arg(va, int), str);
  else if (str[i] == 'k')
    my_putstr("%k");
  else if (str[i] == '%')
    i = check_percent(str, i);
  else
    my_putchar('%');
  return (i);
}

int	sharp(int i, int j, char *str)
{
  i++;
  if (str[i] == 'X')
    {
      my_putstr("0X");
      base(j, 16);
    }
  else if (str[i] == 'x')
    {
      my_putstr("0x");
      base_mini(j, 16);
    }
  else if (str[i] == 'o')
    {
      my_putchar('0');
      base(j, 8);
    }
  else
    i = i;
  return (i);
}

int	adresse(long int va)
{
  if (va == 0)
    my_putstr("(nil)");
  else
    {
      my_putstr("0x");
      base_mini(va, 16);
    }
}

int	check_percent(char *str, int i)
{
  int	j;

  j = 1;
  while (str[i] == '%')
    {
      i++;
      j++;
    }
  if (j % 2 == 0)
    i--;
  else
    i = i - 2;
  j = j / 2;
  while (j != 0)
    {
      my_putchar('%');
      j--;
    }
  return (i);
}
