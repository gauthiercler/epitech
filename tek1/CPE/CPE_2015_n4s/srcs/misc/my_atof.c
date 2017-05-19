/*
** my_atof.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 23 16:33:39 2016 Buyumad Anas
** Last update Mon May 23 16:56:48 2016 Buyumad Anas
*/

#include	"ia.h"

#include	<stdbool.h>

static bool	is_number(char character)
{
  if ((character - 48) >= 0 && (character - 48) <= 9)
    return (true);
  if (character == '.')
    return (true);
  return false;
}

float		my_atof(char *string)
{
  float		value;
  bool		decimal;
  int		index;
  int		count;

  count = 0;
  index = 0;
  value = 0.0;
  decimal = false;
  while (string[index] && is_number(string[index]))
    {
      if (string[index] == '.')
	decimal = true;
      else
	{
	  value = value * 10.0 + (string[index] - 48);
	  (decimal) ? count -= 1 : 0;
	}
      index += 1;
    }
  while (count++ < 0)
    value *= 0.1;
  return (value);
}
