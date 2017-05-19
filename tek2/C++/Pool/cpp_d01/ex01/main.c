/*
** main.c for cpp_d01 in /home/gogo/rendu/tek2/cpp_d01/ex01/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Jan  4 13:45:04 2017 Gauthier Cler
** Last update Wed Jan  4 17:44:10 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<stdbool.h>

int		menger(int size, int depth, int pos_x, int pos_y);

void		format_number(int nb)
{
  if (nb < 100)
    write(1, "0", 1);
  if (nb < 10)
    write(1, "0", 1);
  printf("%d", nb);
  fflush(stdout);
}

int		my_atoi(char *str)
{
  int   	i = 0;
  int   	res = 0;

  if (str[0] == '-')
    return (-my_atoi(str + 1));
  while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
      res = res * 10 + str[i] - '0';
      i++;
    }
  return (res);
}

bool		is_power(int nb, int power)
{
  while (nb % power == 0)
    {
      nb /= power;
      if (nb == 1)
	return true;
    }
  return false;
}

int		main(int ac, char **av)
{
  int		size;
  int		depth;

  if (ac != 3)
    return (1);
  size = my_atoi(av[1]);
  depth = my_atoi(av[2]);
  if (size <= 0 || !is_power(size, 3) || depth < 0 || depth > size)
    return (1);
  menger(size, depth, 0, 0);
  return (0);
}
