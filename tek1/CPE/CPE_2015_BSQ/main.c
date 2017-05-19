/*
** main.c for main in /home/cler_g/rendu/CPE_2015_BSQ
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
**
** Started on  Mon Nov 30 23:35:27 2015 Gauthier Cler
** Last update Fri Dec 11 17:03:19 2015 Gauthier Cler
*/

#include "my.h"

int	main(int ac, char **av)
{
  if (ac < 2)
    return (0);
  bsq(av[1]);
  return (0);
}

void		bsq(char *str)
{
  int		col;
  int		line;
  char		**tab;
  int		i;

  col = nb_col(str);
  line = nb_line(str);
  tab = tab_init(tab, line, col);
  tab = fill_tab(tab, str, col);
  find_square(tab);
  disp_tab(tab);
  loop_free(tab, line);
}

int	nb_line(char *str)
{
  int	a;
  int	i;
  char	buf[10];

  a = open(str, O_RDONLY);
  read(a, buf, 10);
  i = my_getnbr(buf);
  close(a);
  return (i);
}

int	nb_col(char *str)
{
  int	a;
  int	i;
  char	buf[1];

  a = open(str, O_RDONLY);
  if (a == -1)
    exit(0);
  i = read(a, buf, 1);
  if (i == 0)
    exit(0);
  while (buf[0] != '\n')
    read(a, buf, 1);
  read(a, buf, 1);
  i = 0;
  while (buf[0] != '\n')
    {
      read(a, buf, 1);
      i++;
    }
  close(a);
  return (i);
}

void	loop_free(char **tab, int line)
{
  int	i;

  i = 0;
  while (i < line)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
