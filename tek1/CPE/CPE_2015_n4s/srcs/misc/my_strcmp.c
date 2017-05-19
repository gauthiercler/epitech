/*
** my_strcmp.c for ia in /home/gogo/rendu/CPE_2015_n4s/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr 26 22:05:46 2016 Gauthier Cler
** Last update Tue Apr 26 22:05:51 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"ia.h"

int		my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (ERROR);
  while (s1[i] && i < nb)
    {
      if (s1[i] != s2[i])
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}

int		my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (ERROR);
  if (str_len(s1) != str_len(s2))
    return (ERROR);
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}
