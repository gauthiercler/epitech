/*
** my_strcat.c for my_strcat in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 25 11:47:22 2016 Gauthier Cler
** Last update Tue Jan 26 21:29:46 2016 Gauthier Cler
*/

#include	"tekpaint.h"

char		*my_strcat(char	*str1,
			   char	*str2)
{
  int		i;
  int		j;
  char		*res;

  i = 0;
  j = 0;
  res = bunny_malloc(sizeof(char) *
		     my_strlen(str1) + my_strlen(str2) + 1);
  if (res == NULL)
    return (NULL);
  while (str1[i])
    res[j++] = str1[i++];
  i = 0;
  while (str2[i])
    res[j++] = str2[i++];
  res[j] = '\0';
  return (res);
}
