/*
**find_square.c for find_square in /home/gauthier/rendu/CPE_2015_BSQ
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec  7 17:23:46 2015 Gauthier Cler
** Last update Wed Dec  9 22:58:19 2015 Gauthier Cler
*/

#include "my.h"

void			find_square(char **tab)
{
  int			x;
  int			y;
  t_info		info;

  info.x = 0;
  info.y = 0;
  info.taille = 0;
  x = 0;
  y = 0;
  while (tab[y])
    {
      while (tab[y][x])
	{
	  if (tab[y][x] == '.')
	    info = check_square(tab, info, x, y);
	  x++;
	}
      x = 0;
      y++;
    }
  fill_square(tab, info);
}

t_info	check_square(char **tab, t_info info, int x, int y)
{
  int	check;
  int	taille;

  taille = 1;
  check = 1;
  while (check != 0)
    {
      check = check_loop(tab, x, y, taille);
      if (check != 0)
	taille++;
    }
  if (taille > info.taille)
    {
      info.taille = taille;
      info.x = x;
      info.y = y;
    }
  return (info);
}

int	check_loop(char **tab, int x, int y, int taille)
{
  int	taille_x;
  int	taille_y;
  int	x_inc;
  int	y_inc;
  t_max	max;

  max = taille_max(tab, max);
  taille_x = x + taille + 1;
  taille_y = y + taille + 1;
  x_inc = x;
  y_inc = y + taille;
  if (y_inc >= max.y)
    return (0);
  if (loop_x(tab, x_inc, y_inc, taille_x) == 0)
    return (0);
  if (x_inc > max.x)
    return (0);
  x_inc = x + taille;
  y_inc = y;
  if (loop_y(tab, x_inc, y_inc, taille_y) == 0)
    return (0);
  return (1);
}

int	loop_x(char **tab, int x, int y, int taille)
{
  while (x != taille)
    {
      if (tab[y][x] == 'o' || tab[y][x] == '\0')
	return (0);
      x++;
    }
}

int	loop_y(char **tab, int x, int y, int taille)
{
  while (y != taille)
    {
      if (tab[y][x] == 'o' || tab[y][x] == '\0')
	return (0);
      y++;
    }
}
