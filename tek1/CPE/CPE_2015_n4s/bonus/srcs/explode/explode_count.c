/*
** explode_count.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/explode/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 23 15:15:11 2016 Buyumad Anas
** Last update Mon May 23 15:15:16 2016 Buyumad Anas
*/

#include	"ia.h"

int		purge_count(char *string)
{
  int		count;
  int		i;

  i = 0;
  count = 0;
  while (string[i])
    {
      if (count > 0 && (string[i] != ' ' && string[i] != '\t') &&
	  (string[i - 1] == ' ' || string[i - 1] == '\t') && string[i])
	count += 1;
      if (count == 0 && (string[i] != ' ' && string[i] != '\t') && string[i])
	count += 1;
      i += 1;
    }
  return (count);
}

int		explode_count(char *string, char delimiter)
{
  int		count;
  int		i;

  i = 0;
  count = 0;
  while (string[i])
    {
      if (count > 0 && (string[i] == delimiter) && string[i])
	count += 1;
      if (count == 0 && (string[i] != delimiter) && string[i])
	count += 1;
      i += 1;
    }
  return (count);
}
