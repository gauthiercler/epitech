/*
** my_strcmp.c for my_strcmp in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 11 11:57:39 2016 Gauthier Cler
** Last update Tue Jan 26 21:31:36 2016 Gauthier Cler
*/

#include	"tekpaint.h"

int		my_strcmp(unsigned char	*s1,
			  char		*s2)
{
  int		i;

  i = 0;
  if (my_strlen((char *)s1) != my_strlen(s2))
    return (0);
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}

int		my_strcmp_ae(char	*s1,
			     char	*s2)
{
  int		i;

  i = 0;
  if (my_strlen((char *)s1) != my_strlen(s2))
    return (0);
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}
