/*
** my_strncmp.c for my_strncmp in /tmp/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar  1 21:05:20 2016 Gauthier Cler
** Last update Tue Mar  1 21:10:57 2016 Gauthier Cler
*/

#include	"tekgui.h"

int		my_strncmp(char		*s1,
			  char		*s2,
			  int		count)
{
  int		i;

  if (s1 == NULL || s2 == NULL)
    return (0);
  i = 0;
  while (i < count)
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}
