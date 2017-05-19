/*
** str_dup.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:49:56 2016 Buyumad Anas
** Last update Tue Apr 26 15:50:38 2016 Buyumad Anas
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
