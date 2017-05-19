/*
** get_number.c for libc in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/libc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 14:45:59 2016 Buyumad Anas
** Last update Sun Jun  5 18:32:57 2016 Gauthier Cler
*/

#include	<stdlib.h>

/*
** Returns the numeric value of a string
** @params string
** @return converted number
*/
int		get_number(char *string)
{
  int		iterator;
  int		value;
  int		minus;

  iterator = 0;
  minus = 1;
  if (string[0] == '-')
    {
      minus = -1;
      iterator += 1;
    }
  value = 0;
  while (string[iterator])
    {
      value = value * 10 + string[iterator] - '0';
      iterator++;
    }
  return (value * minus);
}
