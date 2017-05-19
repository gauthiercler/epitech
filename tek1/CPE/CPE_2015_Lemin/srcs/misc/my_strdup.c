/*
** my_strdup.c for my_strdup in /home/gogo/rendu/gfx_tekadventure/srcs/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 14 14:47:32 2016 Gauthier Cler
** Last update Sat Apr 23 13:05:47 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

char		*my_strdup(char *str)
{
  int		i;
  char		*res;

  i = 0;
  if (str == NULL)
    return (NULL);
  if ((res = malloc(sizeof(char) * str_len((char *)str) + 1)) == NULL)
    return (p_error("Couldn't malloc\n."));
  while (str[i])
    {
      res[i] = str[i];
      i += 1;
    }
  res[i] = '\0';
  return (res);
}
