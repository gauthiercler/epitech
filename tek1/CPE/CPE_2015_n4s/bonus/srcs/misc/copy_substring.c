/*
** copy_substring.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 23 15:29:38 2016 Buyumad Anas
** Last update Mon May 23 15:29:42 2016 Buyumad Anas
*/

#include	"ia.h"

void		copy_substring(char *str, char *dest, int index, int length)
{
  int		i;

  i = 0;
  while (i < length && str[i])
    {
      dest[i] = str[index + i];
      i += 1;
    }
  dest[i] = '\0';
}
