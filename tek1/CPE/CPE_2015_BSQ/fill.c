/*
** fill.c for fill in /home/cler_g/rendu/CPE_2015_BSQ
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
**
** Started on  Thu Dec  3 13:35:41 2015 Gauthier Cler
** Last update Wed Dec  9 00:35:05 2015 Gauthier Cler
*/

#include "my.h"

char **tab_init(char **tab, int line, int col)
{
  int	i;

  i = 0;
  tab = malloc(sizeof(char*) * line + 1);
  tab[line] = '\0';
  while (i < line)
    {
      tab[i] = malloc(sizeof(char) * col + 1);
      tab[i][col] = '\0';
      i++;
    }
  return (tab);
}

char	**fill_tab(char **tab, char *str, int col)
{
  int	a;
  int	x;
  int	y;
  char	buf[1];

  x = 0;
  y = 0;
  a = open(str, O_RDONLY);
  buf[0] = 1;
  while (buf[0] != '\n')
    read(a, buf, 1);
  while (tab[y])
    {
      while (x < col)
	{
	  read(a, &tab[y][x], 1);
	  x++;
	}
      y++;
      x = 0;
      read(a, buf, 1);
    }
  close(a);
  return (tab);
}

void	disp_tab(char **tab)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (tab[y])
    {
      while (tab[y][x])
	{
	  write(1, &tab[y][x], 1);
	  x++;
	}
      write(1, "\n", 1);
      x = 0;
      y++;
    }
}

t_max	taille_max(char **tab, t_max max)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tab[i][j])
    j++;
  while (tab[i])
    i++;
  max.x = j;
  max.y = i;
  return (max);
}

void    fill_square(char **tab, t_info info)
{
  int   x;
  int   y;

  x = info.x;
  y = info.y;
  while (y < info.y + info.taille)
    {
      while (x < info.x + info.taille)
	{
	  tab[y][x] = 'x';
	  x++;
	}
      x = info.x;
      y++;
    }
}
