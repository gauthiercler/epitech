/*
** my_strdup.c for my_strdup in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar  8 08:43:58 2016 Gauthier Cler
** Last update Mon Mar 14 08:26:16 2016 Gauthier Cler
*/

#include	"raytracer.h"

char    *my_strdup(const char *str)
{
  char  *res;
  int   i;

  i = 0;
  if ((res = bunny_malloc(sizeof(char) * my_strlen((char *)str) + 1)) == NULL)
    return (NULL);
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}
