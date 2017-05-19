/*
** sort_ascii.c for sort_ascii in /home/cler_g/rendu/PSU_2015_my_ls
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Tue Nov 24 23:25:13 2015 Gauthier Cler
** Last update Thu Nov 26 15:21:11 2015 Gauthier Cler
*/

#include "info.h"

void	sort_ascii(t_list *file, int i)
{
  int	j;
  t_list	tmp;

  j = 0;
  while (j < i - 1)
    {
      if (my_strcmp(file[j].name, file[j + 1].name) == 1)
	{
	  tmp = file[j];
	  file[j] = file[j + 1];
	  file[j + 1] = tmp;
	}
      j++;
    }
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i])
    {
      if (str1[i] > str2[i])
	return (1);
      else if (str1[i] < str2[i])
	return (-1);
      i++;
    }
  if (str2[i] != 0)
    return (-1);
  else
    return (0);
}
