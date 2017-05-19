/*
** my_str_to_wortab.c for my_str_to_wortab in /home/gauthier/rendu/PSU_2015_minishell1
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan 14 00:31:40 2016 Gauthier Cler
** Last update Thu May 12 14:25:56 2016 montag_v
*/

#include	<stdlib.h>
#include	"raytracer.h"

void	init_couple(int *i, int *n)
{
  *i = 0;
  *n = 0;
}

int	count_word(char *str, int *nb)
{
  int	n;
  int	i;

  init_couple(&i, &n);
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  *nb = i;
  if (str[i] == '\0' || str[i] == '\n')
    return (0);
  if (str[i] != ' ' && str[i] != '\t')
    {
      n += 1;
      i += 1;
    }
  while (str[i])
    {
      if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != '\0')
	{
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	  n = (str[i] != '\0') ? n + 1 : n + 0;
	}
      i += 1;
    }
  return (n);
}

int	fill_tab(char *str, char *res, int i, int j)
{
  int	car;

  car = 0;
  while (i < j)
    {
      res[car] = str[i];
      car += 1;
      i += 1;
    }
  res[car] = '\0';
  return (i);
}

char	**my_str_to_wordtab(char *str)
{
  char	**res;
  int	i;
  int	j;
  int	string;

  i = 0;
  string = 0;
  if ((res = bunny_malloc(sizeof(char *) * (count_word(str, &i) + 1))) == NULL)
    return (NULL);
  res[count_word(str, &i)] = NULL;
  while (str[i])
    {
      j = i;
      while (str[j] != ' ' && str[j] != '\t' && str[j] != '\0')
	j++;
      if ((res[string] = bunny_malloc(sizeof(char) * (j - i + 1))) == NULL)
	return (NULL);
      i = fill_tab(str, res[string], i, j);
      while ((str[i] == ' ' || str[i] == '\t') && str[j] != '\0')
	i++;
      string += 1;
    }
  return (res);
}
