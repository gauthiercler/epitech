/*
** my_path_to_tab.c for my_path_to_tab in /home/gauthier/rendu/PSU_2015_minishell1/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan 19 09:54:18 2016 Gauthier Cler
** Last update Mon Apr  4 17:03:18 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

int		count_word_tab(char *str, char separator)
{
  int		n;
  int		i;

  i = 0;
  n = 1;
  while (str[i])
    {
      if (str[i] == separator)
	n += 1;
      i += 1;
    }
  return (n);
}

int		fill_tab_separator(char *str, char *res, int i, int j)
{
  int		car;

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

char		**separator_to_tab(char *str, char separator)
{
  char		**res;
  int		i;
  int		j;
  int		string;

  if (str == NULL)
    return (NULL);
  init_couple(&i, &j);
  string = 0;
  res = xmalloc(sizeof(char *) * (count_word_tab(str, separator) + 1));
  while (str[i])
    {
      while (str[j] != separator && str[j] != '\0')
	j++;
      res[string] = xmalloc(sizeof(char) * (j - i + 1));
      i = fill_tab_separator(str, res[string], i, j);
      while (str[i] == separator && str[j] != '\0')
	i++;
      string += 1;
      j = i;
    }
  res[string] = NULL;
  return (res);
}
