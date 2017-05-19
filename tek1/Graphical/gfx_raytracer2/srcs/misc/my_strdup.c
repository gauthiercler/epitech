/*
** my_strdup.c for my_strdup in /home/montag_v/rendu/gfx_raytracer2
** 
** Made by montag_v
** Login   <montag_v@epitech.net>
** 
** Started on  Wed May  4 14:41:22 2016 montag_v
** Last update Wed May  4 15:37:46 2016 montag_v
*/

#include	"raytracer.h"

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
