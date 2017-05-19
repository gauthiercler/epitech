/*
** compile_octets.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/compiler/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 24 21:38:07 2016 Buyumad Anas
** Last update Thu Mar 24 21:52:23 2016 Buyumad Anas
*/

#include	<unistd.h>
#include	"asm.h"

int		write_octets(int fd, int nb_octets, unsigned char *octets)
{
  int		i;

  i = 0;
  while (i < nb_octets)
    {
      write(fd, &octets[i], sizeof(octets[i]));
      i += 1;
    }
  return (SUCCESS);
}

int		compile_octects(int fd, int nb_octets, int value)
{
  unsigned char	octets[nb_octets];
  int		shift;
  int		i;

  i = 0;
  if (nb_octets <= 0)
    return (ERROR);
  if (nb_octets == 1)
    shift = 0;
  else
    shift = (nb_octets - 1) * 8;
  while (i < nb_octets)
    {
      if (shift == 0)
	octets[i] = value & 0xFF;
      else
	octets[i] = (value >> shift) & 0xFF;
      i += 1;
      shift -= 8;
    }
  write_octets(fd, nb_octets, octets);
  return (SUCCESS);
}
