/*
** disp_simple.c for disp_simple in /home/cler_g/rendu/PSU_2015_my_ls
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Sat Nov 28 17:38:02 2015 Gauthier Cler
** Last update Sun Nov 29 18:23:11 2015 Gauthier Cler
*/

#include "info.h"

void	disp_simple(t_list *file, int i)
{
  int	j;

  j = 0;
  while (j < i)
    {
      if (file[j].name[0] != '.')
	{
	  my_putstr(file[j].name);
	  write(1, "\n", 1);
	}
      j++;
    }
}

char	**check_av(int *ac, char **av, int k)
{
  int	ac2;

  ac2 = *ac;
  if (ac2 < 2)
    {
      ac2++;
      av[1] = ".";
    }
  else if (ac2 >= 2 && k == 0)
    {
      av[ac2] = ".";
      ac2++;
    }
  else
    k = 0;
  *ac = ac2;
  return (av);
}

void	disp_name(char *name)
{
  my_putstr(name);
  my_putstr(":\n");
}

int	add_blocks(char c, int blocks, int nb_c)
{
  if (c != '.')
    blocks += nb_c / 2;
  return (blocks);
}

t_list	*add_link(char *str, int i, t_list *file, int j)
{
  char	res[256];
  int	r;

  r = readlink(str, res, sizeof(res));
  res[r] = '\0';
  file[j].link_name = res;
  return (file);
}
