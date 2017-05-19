/*
** write_coding_octet.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/compiler/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 24 22:20:46 2016 Buyumad Anas
** Last update Fri Mar 25 11:11:55 2016 Gauthier Cler
*/

#include	"asm.h"

int		to_power(int power, int value)
{
  int		pow;
  int		number;

  number = value;
  if (power == 0)
    return (1);
  pow = power;
  while (pow > 1)
    {
      value *= number;
      pow -= 1;
    }
  return (value);
}

int		write_coding_octet(int fd, unsigned char *binary_octet)
{
  int		coeff;
  int		value;
  int		i;

  i = 7;
  value = 0;
  coeff = 0;
  while (i >= 0)
    {
      value += to_power(coeff, 2) * (binary_octet[i] - 48);
      i -= 1;
      coeff += 1;
    }
  compile_octects(fd, 1, value);
  return (SUCCESS);
}
