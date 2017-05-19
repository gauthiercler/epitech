/*
** str_dup.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:49:56 2016 Buyumad Anas
** Last update Sun May  1 11:51:26 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"perfection.h"

char		*str_dup(char *str)
{
  int		i;
  char		*res;

  i = 0;
  if (str == NULL)
    return (NULL);
  res = xmalloc(sizeof(char) * str_len((char *)str) + 1);
  while (str[i])
    {
      res[i] = str[i];
      i += 1;
    }
  res[i] = '\0';
  return (res);
}
