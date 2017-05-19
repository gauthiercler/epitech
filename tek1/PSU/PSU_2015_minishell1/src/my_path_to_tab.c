/*
** my_path_to_tab.c for my_path_to_tab in /home/gauthier/rendu/PSU_2015_minishell1/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan 19 09:54:18 2016 Gauthier Cler
** Last update Sat Jan 23 18:29:06 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"../include/info.h"

int	count_word_path(char *str)
{
  int	n;
  int	i;

  i = 0;
  n = 1;
  while (str[i])
    {
      if (str[i] == ':')
	n += 1;
      i += 1;
    }
  return (n);
}

char	**my_path_to_tab(char *str)
{
  char	**res;
  int	i;
  int	j;
  int	string;

  if (str == NULL)
    return (NULL);
  init_var(&i, &j);
  string = 0;
  if ((res = malloc(sizeof(char *) * (count_word_path(str) + 1))) == NULL)
    malloc_error();
  while (str[i])
    {
      while (str[j] != ':' && str[j] != '\0')
	j++;
      if ((res[string] = malloc(sizeof(char) * (j - i + 1))) == NULL)
	malloc_error();
      i = fill_tab_path(str, res[string], i, j);
      while (str[i] == ':' && str[j] != '\0')
	i++;
      string += 1;
      j = i;
    }
  res[string] = NULL;
  return (res);
}

int	fill_tab_path(char *str, char *res, int i, int j)
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
