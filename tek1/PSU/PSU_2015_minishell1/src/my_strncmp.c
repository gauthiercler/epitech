/*
** my_strncmp.c for my_strncmp in /home/gauthier/rendu/PSU_2015_minishell1/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Jan 20 13:51:27 2016 Gauthier Cler
** Last update Wed Jan 20 14:01:51 2016 Gauthier Cler
*/

#include	"../include/info.h"

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  if (my_strlen(s1) < nb)
    return (0);
  while (i < nb)
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}
