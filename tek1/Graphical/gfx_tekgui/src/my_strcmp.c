/*
** my_strcmp.c for my_strcmp in /home/gogo/rendu/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Feb 17 18:00:07 2016 Gauthier Cler
** Last update Fri Feb 26 14:23:14 2016 Gauthier Cler
*/

#include	"tekgui.h"

int		my_strcmp(char		*s1,
			  char		*s2)
{
  int		i;

  if (s1 == NULL || s2 == NULL)
    return (0);
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
