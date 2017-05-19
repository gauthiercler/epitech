/*
** my_strdup.c for my_strdup in /home/gogo/rendu/gfx_tekadventure/srcs/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 14 14:47:32 2016 Gauthier Cler
** Last update Thu Apr 14 15:37:27 2016 valentin montagne
*/

#include	"adventure.h"

char		*my_strdup(const char *str)
{
  int		i;
  char		*res;

  i = 0;
  if (str == NULL)
    return (NULL);
  if ((res = bunny_malloc(sizeof(char) * str_len((char *)str) + 1)) == NULL)
    return (NULL);
  while (str[i])
    {
      res[i] = str[i];
      i += 1;
    }
  res[i] = '\0';
  return (res);
}
