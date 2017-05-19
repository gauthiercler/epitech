/*
** my_strcmp.c for my_strcmp in /home/gauthier/rendu/gfx_fdf2/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Dec 15 23:28:41 2015 Gauthier Cler
** Last update Wed Dec 16 11:13:52 2015 Gauthier Cler
*/

#include	"fdf.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (0);
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}
