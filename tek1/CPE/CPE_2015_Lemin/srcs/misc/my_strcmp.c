/*
** my_strcmp.c for asm in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar 22 18:41:52 2016 Gauthier Cler
** Last update Fri Apr 22 11:52:26 2016 montag_v
*/

#include	<stdlib.h>
#include	"lemin.h"

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
