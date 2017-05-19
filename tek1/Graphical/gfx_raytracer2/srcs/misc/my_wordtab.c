/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/montag_v/rendu/PSU_2015_minishell1
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Mon Jan 18 09:22:41 2016 valentin montagne
** Last update Mon May 16 01:34:56 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"raytracer.h"

static int	nb_word(char *av, char separator)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (av[i])
    {
      if (av[i] == separator)
	{
	  j++;
	  while (av[i] == separator)
	    i++;
	}
      if (av[i] != '\0')
	i++;
    }
  return (++j);
}

static int	fill_line(char **str, char *av, int nbw, char separator)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (av[i + j] != separator && av[i + j])
    j++;
  if ((str[nbw] = bunny_malloc(j + 1)) == NULL)
    return (-1);
  j = 0;
  while (av[i] != separator && av[i])
    {
      str[nbw][j] = av[i];
      i++;
      j++;
    }
  str[nbw][j] = '\0';
  return (i);
}

static int	do_wordtab(char **str, char *av, char separator, int nb)
{
  int		i;
  int		j;
  int		check;

  i = 0;
  j = 0;
  while (av[i] == separator)
    i++;
  while (j < nb)
    {
      while (av[i] == separator)
	i++;
      check = fill_line(str, av + i, j, separator);
      if (check == -1)
	return (-1);
      i += check;
      j += 1;
    }
  return (0);
}

char		**my_wordtab(char *av, char separator)
{
  char		**str;
  int		nb;

  nb = nb_word(av, separator);
  if ((str = bunny_malloc((nb + 1) * sizeof(char *))) == NULL)
    return (NULL);
  if (do_wordtab(str, av, separator, nb) == -1)
    return (NULL);
  str[nb] = NULL;
  return (str);
}
