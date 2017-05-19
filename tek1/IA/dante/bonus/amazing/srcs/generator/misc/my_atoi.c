/*
** my_atoi.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:49:03 2016 Buyumad Anas
** Last update Tue Apr 26 16:08:22 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"perfection.h"

int             my_atoi(char *str)
{
  int           i;
  int           res;

  if (str == NULL)
    return (ERROR);
  if (str[0] == '-')
    return (-my_atoi(str + 1));
  i = 0;
  res = 0;
  while (str[i])
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (ERROR);
      res = res * 10 + str[i] - '0';
      i++;
    }
  return (res);
}
