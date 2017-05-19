/*
** reverse_integer.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/compiler/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Mar 25 17:37:31 2016 Buyumad Anas
** Last update Fri Mar 25 17:42:55 2016 Buyumad Anas
*/

#include	"asm.h"

int		reverse_integer(int number)
{
  unsigned char	shift;
  int		backup;

  backup = number;
  number = 0;
  shift = 0;
  while (shift < sizeof(number) * 8)
    {
      number <<= 8;
      number |= ((backup >> shift) & 0xFF);
      shift += 8;
    }
  return (number);
}
