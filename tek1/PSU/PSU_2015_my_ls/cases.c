/*
** cases.c for cases in /home/cler_g/rendu/PSU_2015_my_ls
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Sun Nov 29 13:15:18 2015 Gauthier Cler
** Last update Sun Nov 29 21:53:57 2015 Gauthier Cler
*/

#include "info.h"

int	nb_arg(char **av, int k)
{
  int	i;

  i = 1;
  k = 0;
  while (av[i])
    {
      if (av[i][0] != '-')
	k++;
      i++;
    }
  return (k);
}

void	cases(t_list *file, t_flags flags, int i, int k)
{
  int	blocks;
  char	*name;

  name = file[0].name_folder;
  blocks = file[0].blocks;
  if (k > 1 && flags.d == 0)
    disp_name(name);
  if (flags.t == 1)
    while (check_sort_time(file, i) != 1)
      file = sort_time(file, i);
  if (flags.r == 1)
    file = reverse_list(file, i);
  if (flags.d == 0 && flags.l == 1)
    disp_blocks(blocks);
  if ((flags.d == 1 && flags.l == 1) || (flags.d == 1 && flags.l == 0))
    {
      my_putstr(name);
      my_putchar('\n');
    }
  else if (flags.l == 1 && flags.d == 0)
    disp_ls(file, i);
  else
    disp_simple(file, i);
}

t_list	*sort_time(t_list *file, int i)
{
  int	j;
  t_list	tmp;

  j = 0;
  while (j < i - 1)
    {
      if (file[j].time_int < file[j + 1].time_int)
	{
	  tmp = file[j];
	  file[j] = file[j + 1];
	  file[j + 1] = tmp;
	}
      j++;
    }
  return (file);
}

int	check_sort_time(t_list *file, int i)
{
  int	j;

  j = 0;
  while (j < i - 1)
    {
      if (file[j].time_int < file[j + 1].time_int)
	return (0);
      j++;
    }
  return (1);
}

t_list	*reverse_list(t_list *file, int i)
{
  t_list	*reverse;
  int	j;
  int	k;

  j = 0;
  k = i - 1;
  reverse = malloc(sizeof(t_list) * i);
  while (j < i)
    {
      reverse[j] = file[k];
      j++;
      k--;
    }
  return (reverse);
}
