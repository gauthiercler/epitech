/*
** get_value.c for get_value in /home/montag_v/rendu/CPE_2015_corewar/asm/srcs/get_value
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Wed Mar 23 11:27:16 2016 valentin montagne
** Last update Wed Mar 23 17:03:18 2016 Buyumad Anas
*/

#include	"asm.h"

int		get_ins(t_instruction *instructions, char *arg)
{
  int		i;

  i = 0;
  while (instructions[i].name)
    {
      if (my_strcmp(instructions[i].name, arg) == 0)
	return (i);
      i++;
    }
  return (-1);
}

int		get_value(t_instruction *instructions, char *arg, int type)
{
  int		i;
  int		neg;
  int		nb;

  i = 0;
  nb = 0;
  neg = 0;
  if (type == DLAB || type == ILAB)
    return (LABEL_ERROR);
  if (type == INS)
    return (get_ins(instructions, arg));
  while (arg[i])
    {
      if (arg[i] == '-')
	neg = 1;
      if (arg[i] >= '0' && arg[i] <= '9')
	nb = nb * 10 + (arg[i] - 48);
      i++;
    }
  if (neg == 1)
    return (nb * -1);
  return (nb);
}
