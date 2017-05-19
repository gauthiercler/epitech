/*
** type.c for type in /home/montag_v/rendu/CPE_2015_corewar/asm/srcs/type
** 
** Made by valentin montagne
** Login   <montag_v@epitech.net>
** 
** Started on  Tue Mar 22 19:01:02 2016 valentin montagne
** Last update Wed Mar 23 13:58:18 2016 Gauthier Cler
*/

#include	"asm.h"

int		get_dir(char *arg)
{
  int		i;

  i = 0;
  while (arg[i] == '\\')
    i += 1;
  if (arg[i] == DIRECT_CHAR)
    i += 1;
  else
    return (0);
  while (arg[i])
    {
      if (!(arg[i] >= '0' && arg[i] <= '9') && arg[i] != '-')
	return (0);
      i++;
    }
  return (1);
}

int		get_reg(char *arg)
{
  int		nb;

  if (arg[0] != 'r')
    return (0);
  nb = my_getnbr(arg + 1);
  if (nb > REG_NUMBER || nb <= 0)
    return (0);
  return (1);
}

int		get_inst(t_instruction *inst, char *arg)
{
  int		i;

  i = 0;
  while (inst[i].name)
    {
      if (my_strcmp(inst[i].name, arg) == 0)
	return (1);
      i++;
    }
  return (0);
}

int		get_type(t_instruction *inst, char *arg)
{
  int		i;

  if ((i = get_lab(arg)) > 0)
    return (i);
  i = 0;
  if (get_inst(inst, arg))
    return (INS);
  if (get_reg(arg))
    return (REG);
  if (get_dir(arg))
    return (DIR);
  while (arg[i])
    {
      if (!(arg[i] >= '0' && arg[i] <= '9') && arg[i] != '-')
	return (BAD);
      i++;
    }
  return (IND);
}
