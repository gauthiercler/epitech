/*
** my_strdup.c for my_strdup in /home/gogo/rendu/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb 15 13:49:08 2016 Gauthier Cler
** Last update Mon Feb 29 07:36:33 2016 Gauthier Cler
*/

#include "tekgui.h"

char    *my_strdup(const char *str)
{
  char  *res;
  int   i;
  int   j;

  if (str == NULL)
    return (NULL);
  i = 0;
  j = my_strlen((char *)str);
  res = bunny_malloc(sizeof(char) * j + 1);
  res[j] = '\0';
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  return (res);
}
