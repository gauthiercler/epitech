/*
** main.c for main in /home/cler_g/rendu/PSU_2015_my_ls
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Mon Nov 23 10:54:20 2015 Gauthier Cler
** Last update Sun Nov 29 18:24:57 2015 Gauthier Cler
*/

#include "info.h"

void	disp_ls(t_list *file, int i)
{
  int	j;

  j = 0;
  while (j < i)
    {
      if (file[j].name[0] != '.')
	{
	  my_putstr(file[j].droits);
	  write(1, " ", 1);
	  my_put_nbr(file[j].link);
	  write(1, " ", 1);
	  my_putstr(file[j].uid);
	  write(1, " ", 1);
	  my_putstr(file[j].gid);
	  write(1, " ", 1);
	  my_put_nbr(file[j].size);
	  write(1, " ", 1);
	  my_putstr(file[j].time);
	  write(1, " ", 1);
	  my_putstr(file[j].name);
	  write(1, "\n", 1);
	}
      j++;
    }
}

int	main(int ac, char **av)
{
  t_list	*file;
  t_flags	flags;
  int	i;
  int	j;
  int	k;

  j = 0;
  k = nb_arg(av, k);
  av = check_av(&ac, av, k);
  flags = get_flags(av, flags);
  while (++j < ac)
    {
      if (av[j][0] != '-')
	{
	  if (nb_fichier(av[j]) == -1)
	    error_name(av[j]);
	  else
	    {
	      file = malloc(sizeof(t_list) * nb_fichier(av[j]));
	      i = read_to_list(av[j], file, flags);
	      droits(file, i);
	      cases(file, flags, i, k);
	    }
	}
    }
}

t_flags	init_flags(t_flags flags)
{
  flags.l = 0;
  flags.r = 0;
  flags.t = 0;
  flags.d = 0;
  flags.R = 0;
  return (flags);
}

t_flags	get_flags(char **av, t_flags flags)
{
  int	i;
  int	j;

  i = 1;
  j = 1;
  flags = init_flags(flags);
  while (av[i])
    {
      if (av[i][0] == '-')
	{
	  while (av[i][j])
	    {
	      flags = get_flags_loop(i, j, av, flags);
	      j++;
	    }
	  j = 1;
	}
      i++;
    }
  return (flags);
}

t_flags	get_flags_loop(int i, int j, char **av, t_flags flags)
{
  if (av[i][j] == 'l')
    flags.l = 1;
  else if (av[i][j] == 'r')
    flags.r = 1;
  else if (av[i][j] == 't')
    flags.t = 1;
  else if (av[i][j] == 'd')
    flags.d = 1;
  else if (av[i][j] == 'R')
    flags.R = 1;
  j++;
  return (flags);
}
